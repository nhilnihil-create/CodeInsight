#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll mod = 1e9+7;

int main(){
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];
    priority_queue<pair<int,int>> even,odd;
    map<int,int> o,e;
    for(int i = 0; i < n; i += 2){
        o[v[i]]++;
        e[v[i+1]]++;
    }
    for(int i = 0; i < n; i += 2){
        even.push({o[v[i]],v[i]});
        odd.push({e[v[i+1]],v[i+1]});
    }
    even.push({-1,-1});
    odd.push({-1,-1});
    while(!odd.empty() || !even.empty()){
        pair<int,int> od,ev;
        od = odd.top();
        ev = even.top();
        if(od.second == -1 || ev.second == -1){
            cout << n/2 << endl;
            return 0;
        }
        else if(od.second != ev.second){
            cout << n-od.first-ev.first << endl;
            //cout << od.second << " " << ev.second << endl;
            return 0;
        }
        else if(od.first > ev.first) even.pop();
        else if(od.first < ev.first) odd.pop();
        else{
            pair<int,int> a,b;
            odd.pop(); even.pop();
            a = odd.top(); b = even.top();
            even.push(ev);odd.push(od);
            if(a.first > b.first) odd.pop();
            else even.pop();
        }
    }

}