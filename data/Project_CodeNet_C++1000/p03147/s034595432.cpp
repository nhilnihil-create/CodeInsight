
#include <bits/stdc++.h>

#define PI 3.14159265359
#define rep(i,a,n) for(int i=a;i<(int)n;++i)
#define SZ(x) ((int)(x).size())	//size() unsigned -> int
#define descSort(a) sort(a.begin(),a.end(),std::greater<int>())
using namespace std;
typedef long long ll;
const ll INF = 1e9 + 7;
ll gcd(ll x,ll y){
    if(x%y==0)return y;
    return gcd(y,x%y);
}
int main(void){
    int n;
    cin>>n;
    vector<int> h(n);
    rep(i,0,n){
        cin>>h[i];
    }
    
    int ans=h[0];
    rep(i,0,n-1){
        int tmp=h[i];
        if(tmp<h[i+1]){
            ans+=h[i+1]-tmp;
        }
    }

    cout<<ans<<endl;
    return 0;
}