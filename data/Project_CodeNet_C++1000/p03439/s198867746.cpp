#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < b; i++)

int main(){
    int N; cin >> N;
    int lb = 0, ub = N;
    map<int,string> mp;
    cout << 0 << endl;
    string s; cin >> s;
    mp[0] = s;
    if(s == "Vacant"){
        cout << 0 << endl;
        return 0;
    }
    while(1){
        int m = (lb + ub) / 2;
        cout << m << endl;
        cin >> s;
        mp[m] = s;
        if(s == "Vacant"){
            cout << m << endl;
            return 0;
        }
        if((m - lb) % 2 == 0){
            if(mp[m] == mp[lb]) lb = m;
            else ub = m;
        }else{
            if(mp[m] == mp[lb]) ub = m;
            else lb = m;
        }
    }
    return 0;
}