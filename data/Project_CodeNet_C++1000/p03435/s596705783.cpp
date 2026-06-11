#include <bits/stdc++.h>

#define PI 3.14159265359
#define rep(i,a,n) for(int i=a;i<(int)n;++i)
#define SZ(x) ((int)(x).size())	//size() unsigned -> int
#define descSort(a) sort(a.begin(),a.end(),std::greater<int>())
using namespace std;
typedef long long ll;
const ll INF = 1e9 + 7;
ll gcd(ll x,ll y){
    if(y==0)return x;
    return gcd(y,x%y);
}
ll LCM(ll a, ll b){
    return a/gcd(a,b)*b;
}

int main(void)
{
    int c[3][3];
    rep(i,0,3){
        rep(j,0,3){
            cin>>c[i][j];
        }
    }
    int a[3],b[3];
    a[0]=0;
    rep(i,0,3){
        b[i]=c[0][i]-a[0];
    }
    rep(i,1,3){
        a[i]=c[i][0]-b[0];
    }

    rep(i,0,3){
        rep(j,0,3){
            if(c[i][j] != a[i]+b[j]){ 
                cout<<"No"<<endl;
                return 0;
            }
        }
    }
    cout<<"Yes"<<endl;
    return 0;
}