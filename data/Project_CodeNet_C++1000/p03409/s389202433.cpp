#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int n;
    cin >> n;
    set<pair<int, int>> red;
    vector<pair<int, int>> blue(n);
    for(int i=0; i<n; i++){
        int a,b;
        cin >> a >> b;
        pair<int, int> p=make_pair(a,b);
        red.insert(p);
    }
    for(int i=0; i<n; i++){
        int c,d;
        cin >> c >> d;
        pair<int, int> p=make_pair(c,d);
        blue.at(i)=p;
    }
    sort(blue.begin(), blue.end());
    int ans=0;
    for(int i=0; i<n; i++){
        int a,b;
        a=blue.at(i).first;
        b=blue.at(i).second;
        bool possible=false;
        int pair_c, pair_d=0;
        for(auto p:red){
            int c,d;
            c=p.first;
            d=p.second;
            //cout << "c" << c << "d" << d << " ";
            if(c<a && d<b){
                possible = true;
                if(d >= pair_d){
                    pair_d=d;
                    pair_c=c;
                }
            }
        }
        if(possible){
            ans++;
            pair<int,int> q=make_pair(pair_c, pair_d);
            red.erase(q);
            //cout << "blue" << a << b << "red" << pair_c << pair_d << endl;
        }
        for(auto p:red){
            //cout << p.first << p.second << " ";
        }
        //cout << endl;
    }
    cout << ans << endl;
}