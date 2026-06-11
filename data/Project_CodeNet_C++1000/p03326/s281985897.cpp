#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
typedef long long ll;
typedef pair<int,int> pp;
const int INF = 1e9;
const int MOD = 1000000007;

bool s(vector<ll> a,vector<ll> b){
        ll sa = 0,sb = 0;
        for(ll p:a) sa += p;
        for(ll p:b) sb += p;
        return sa > sb;
}        


int main() {
        int n,m;
        ll ans = 0;
        cin >> n >> m;
        vector<vector<ll>> xyz(n,vector<ll>(3,0));
        rep(i,n){
                 ll a,b,c;
                cin >> a >> b >> c;
                xyz.at(i).at(0) = a;
                xyz.at(i).at(1) = b;
                xyz.at(i).at(2) = c;
        }
        
        
        
        rep(i,pow(2,3)){
                vector<vector<ll>> now = xyz;
                rep(j,3){
                         if(i >> j & 1 ){
                                         rep(k,n){
                                                  now.at(k).at(j) *= -1;
                                }
                        }
                }
                sort(now.begin(),now.end(),s);
                //rep(i,n) cout << now.at(i).at(0) << " "<< now.at(i).at(1) << " "<< now.at(i).at(2) << endl;
                ll p = 0;
                rep(j,m){
                         p += now.at(j).at(0) + now.at(j).at(1) + now.at(j).at(2);
                }
                ans = max(ans,p);      
        }
        
        cout << ans  << endl;
        
        return 0;
}

