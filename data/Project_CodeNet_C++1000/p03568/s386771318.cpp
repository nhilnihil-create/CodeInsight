#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, n) for(int i=0;i<(int)n;i++)
#define PI acos(-1)
#define fast_io ios_base::sync_with_stdio(false) ; cin.tie(0); cout.tie(0);
ll mod=1e9+7;


int main(){
    fast_io

    int n;
    cin>>n;
    int a[n];
    rep(i,n) cin>>a[i];

    int all=1, bad=1;
    rep(i,n){
        all*=3;
        if(a[i]%2==0) bad*=2;
    }
    cout<<all-bad<<endl;
    
    return 0;
}