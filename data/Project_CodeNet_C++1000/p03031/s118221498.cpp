#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
#define cans cout << ans << endl
#define cyes cout << "Yes" << endl
#define cno cout << "No" << endl
typedef long long ll;


int main(){
    int n,m;
    cin >> n >> m;
    vector<int> k(m);
    vector<int> s[m];
    vector<int> p(m);
    int ans = 0;
    rep(i,m){
        cin >> k[i];
        rep(j,k[i]){
            int t;
            cin >> t;
            t--;
            s[i].push_back(t);
        }
    }
    rep(i,m) cin >> p[i];
    rep(i,1<<n){
        vector<bool> sw(n,false);
        vector<int> lb(m);
        rep(j,n){
            if(i>>j & 1) sw[j]=true;
        }
        cout << endl;
        rep(j,m){
            rep(ij,k[j]){
                if(sw[s[j][ij]]) lb[j]++; 
            }
        }
        bool check = true;
        rep(j,m){
            if(lb[j]%2 != p[j]) check = false;
        }
        if(check) ans++;
    }
    cout << ans << endl;
    return 0;
}