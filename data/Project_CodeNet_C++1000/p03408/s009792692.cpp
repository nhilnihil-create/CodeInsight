
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()


int main(){
    map<string, int> p;
    int n; cin >> n;
    rep(i,n){
        string s;
        cin >> s;
        p[s] ++;
    }
    int m; cin >> m;
    rep(i,m){
        string t;
        cin >> t;
        p[t] --;
    }
    int a=0;
    for(auto x:p){
        a=max(a,x.second);
    }
    cout << a << endl;
}