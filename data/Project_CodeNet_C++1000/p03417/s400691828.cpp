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
    
    ll n,m;
    cin>>n>>m;

    if(n==1&&m == 1){
        cout<<1<<endl;
    }else if(n==1 && m!=1){
        cout<<m-2<<endl;
    }else if(n!=1 && m==1){
        cout<<n-2<<endl;
    }else{
        cout<<(n-2)*(m-2)<<endl;
    }


    return 0;
}
