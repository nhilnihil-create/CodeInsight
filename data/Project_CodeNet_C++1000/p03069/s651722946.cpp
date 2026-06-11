#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define REP(i,s,n) for(int i=s;i<n;i++)
#define all(a) a.begin(),a.end()
typedef long long ll;
const ll inf = 1e9;
int main(){
    int n;
    string s;
    cin >> n >> s;
    vector<int> cb(n, 0), cw(n, 0);
    int b = 0, w = 0;
    REP(i,1,n){
        if(s[i-1] == '#')b++;
        cb[i] = b;
    }
    for(int i=n-2;i>=0;i--){
        if(s[i+1] == '.')w++;
        cw[i] = w;
    }
    int mi = inf;
    rep(i,n)mi = min(mi, cw[i]+cb[i]);
    cout << mi << endl;
    
    return 0;
}