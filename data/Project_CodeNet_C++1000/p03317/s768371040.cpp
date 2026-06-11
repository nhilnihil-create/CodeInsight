
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

ll LCM(int a, int b){
    return a*b/gcd(a,b);
}
int main(void){
    int n,k;
    cin>>n>>k;
    vector<int> a(n);
    int mi=0,i;
    rep(i,0,n){
        cin>>a[i];
    }
    sort(a.begin(),a.end());

    int ans=1;
    for(int i=k;i<n;i+=k-1)ans++;

    cout<<ans<<endl;

    return 0;
}