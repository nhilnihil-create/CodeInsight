
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
    int n,m;
    cin>>n>>m;
    char f[55][55];
    rep(i,0,n){
        rep(j,0,m)cin>>f[i][j];
    }
    int dx[4]={-1,0,1,0};
    int dy[4]={0,1,0,-1};
    rep(i,0,n){
        rep(j,0,m){
            if(f[i][j]=='#'){
                bool ok=false;
                rep(k,0,4){
                    if(f[i+dx[k]][j+dy[k]]=='#'){
                        ok=true;
                        break;
                    }else ok=false;
                }
                if(!ok){cout<<"No"<<endl;return 0;}
            }
        }
    }
    cout<<"Yes"<<endl;
    return 0;
}