
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
    int n,sum=0;
    cin>>n;
    vector<int> a;
    a.push_back(0);
    rep(i,1,n+1){
        int in;
        cin>>in;
        a.push_back(in);
        sum+=abs(a[i]-a[i-1]);
    }
    a.push_back(0);
    sum+=abs(a[n+1]-a[n]);
    //cout<<sum<<endl;
    rep(i,1,n+1){
        int ans=sum-(abs(a[i]-a[i+1])+abs(a[i]-a[i-1]))+abs(a[i+1]-a[i-1]);
        cout<<ans<<endl;
    }
    return 0;

}