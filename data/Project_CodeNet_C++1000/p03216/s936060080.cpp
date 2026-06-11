#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9+7;
//const long long MOD = ;
const long long INF_LL = 1e18+3; const int INF_int = 1e9+3;
#define ll long long
#define rep(i,n) for(int i = 0;i<n;i++)
#define lrep(i,n) for(long long i = 0;i<n;i++)
#define All(a) a.begin(),a.end()
#define Debug_Output_ALL(a) for(auto itr = a.begin();itr!=a.end();itr++) cout << *itr << " ";cout << endl;
int main(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    int q;
    cin >> q;
    vector<ll> ansvec;
    rep(i,q){
        int dist;
        cin >> dist;
        ll ans = 0;
        ll d,m,dm;
        d = m = dm = 0;
        rep(j,n){
            if(s[j]=='D') d++;
            else if(s[j]=='M'){
                m++;
                dm+=d;
            }
            else if(s[j]=='C'){
                ans+=dm;
            }
            if(j>=dist-1){
                if(s[j-dist+1]=='D'){
                    d--;
                    dm-=m;
                }
                else if(s[j-dist+1]=='M'){
                    m--;
                }
            }
        }
        ansvec.push_back(ans);
    }
    rep(i,ansvec.size()) cout << ansvec[i] << endl;
}