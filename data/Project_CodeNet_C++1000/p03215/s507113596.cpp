#include <bits/stdc++.h>
using namespace std;
using Int = long long;
typedef pair<int,int> P;
typedef vector<int> Vi;
int const MOD = 1000000007;
double const PI = acos(-1);
template<class T> inline bool chmin(T& a, T b) { if (a > b) { return a = b; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { return a = b; } return false; }


int main(){
    cin.tie(0); ios::sync_with_stdio(false);
   
    int n,k; cin>>n>>k; Int a[n],ans=0; vector<Int> s;
    for (int i = 0; i < n; i++)cin>>a[i];
    for (int i = 0; i < n; i++){
        Int sum=0;
        for (int j = i; j < n; j++){sum+=a[j]; s.push_back(sum);}
    }
    for (int i = 40; i >= 0; i--){
        vector<Int> use;
        for (auto j:s){if((j>>i)&1LL)use.push_back(j);}
        if(use.size()>=k){ans+=(1LL<<i); s=use;}
    }
    cout<<ans<<'\n';
}