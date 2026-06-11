#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, n) for(int i=0;i<(int)n;i++)
#define PI acos(-1)
#define fast_io ios_base::sync_with_stdio(false) ; cin.tie(0); cout.tie(0);
ll mod=1e9+7;
ll oddsolve(ll a){
    return (a+1)/2 % 2;
}
ll solve(ll a){
    if(a%2==0){
        return oddsolve(a+1)^(a+1);
    }else{
        return oddsolve(a);
    }
}

int main(){
    fast_io

    ll a, b;
    cin>>a>>b;
    cout<<(solve(b)^solve(a-1))<<endl;
    return 0;

}
