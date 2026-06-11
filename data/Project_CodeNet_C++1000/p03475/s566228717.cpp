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

int main(void)
{
    int n;
    cin>>n;
    vector<int> c(n-1),s(n-1),f(n-1);
    rep(i,0,n-1){
        cin>>c[i]>>s[i]>>f[i];
    }

    rep(i,0,n){
        if(i==n-1){ cout<<0<<endl;break;}
        ll arrival=0;
        rep(j,i,n-1){
            if(arrival<s[j]) arrival=s[j];
            else{
                if(arrival%f[j]){
                    ll div=(arrival-s[j])/f[j];
                    //arrival=s[j]+div*f[j]+f[j];
                    arrival=arrival+f[j]-(arrival%f[j]);
                }
            }
            arrival+=c[j];
        }
        cout<<arrival<<endl;
    }
    return 0;
}