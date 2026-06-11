
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
    int ans=0;
    vector<int> a(3);
    cin>>a[0]>>a[1]>>a[2];
    while(a[0]!=a[1]||a[1]!=a[2]){
        sort(a.begin(),a.end());
        if(a[2]-a[0]>1)a[0]+=2;
        else if(a[2]-a[0]>0 && a[2]-a[0]>0){
            a[0]++;
            a[1]++;
        }
        //cout<<a[0]<<" "<<a[1]<<" "<<a[2]<<endl;
        ans++;
    }
    cout<<ans<<endl;
    return 0;

}