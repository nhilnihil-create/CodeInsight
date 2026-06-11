#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<ll, ll>;
#define rep(i, n) for(int i=0;i<(int)n;i++)
#define PI acos(-1)
#define fast_io ios_base::sync_with_stdio(false) ; cin.tie(0); cout.tie(0);
ll mod=1e9+7;

int main(){
    
    int n;
    cin>>n;
    vector<ll> X(n);
    rep(i,n) cin>>X[i];
    vector<ll> res = X;
    sort(X.begin(), X.end());
    ll mid = X[n/2];
    rep(i,n){
        if(res[i]<mid){
            cout<<mid<<endl;
        }else{
            cout<<X[n/2-1]<<endl;
        }
    }
    

    return 0;
}
