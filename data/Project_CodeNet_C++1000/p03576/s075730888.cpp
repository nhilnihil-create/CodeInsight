#include <iostream>
#include <complex>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdio>
#include <numeric>
#include <cstring>
#include <ctime>
#include <cstdlib>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <cmath>
#include <bitset>
#include <cassert>
#include <queue>
#include <stack>
#include <deque>
#include <random>
#include <iomanip>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
typedef long long int ll;
typedef long double ld;
typedef pair<int,ll> P;
typedef pair<P,P> PP;
const ll MOD=1000000007;
const ll MAX_N=500010;
const ll INF=4999999996000000001;



int main(){
    int n,K;
    cin>>n>>K;
    vector<ll> x(n),y(n);
    for(int i=0;i<n;i++){
        cin>>x[i]>>y[i];
    }

    ll ans=INF;
    if(K==2){
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                ll ux=max(x[i],x[j]);
                ll lx=min(x[i],x[j]);
                ll uy=max(y[i],y[j]);
                ll ly=min(y[i],y[j]);
                ll buf=(ux-lx)*(uy-ly);
                ans=min(buf,ans);
            }
        }
        cout<<ans<<endl;
        return 0;
    }

    if(K==3){
        for(int i=0;i<n-2;i++){
            for(int j=i+1;j<n-1;j++){
                for(int k=j+1;k<n;k++){
                    ll ux=max(max(x[i],x[j]),x[k]);
                    ll uy=max(max(y[i],y[j]),y[k]);
                    ll lx=min(min(x[i],x[j]),x[k]);
                    ll ly=min(min(y[i],y[j]),y[k]);
                    ll buf=(ux-lx)*(uy-ly);
                    ans=min(buf,ans);
                }
            }
        }
        cout<<ans<<endl;
        return 0;
    }

    for(int i=0;i<n-3;i++){
        for(int j=i+1;j<n-2;j++){
            for(int k=j+1;k<n-1;k++){
                for(int l=k+1;l<n;l++){
                    ll ux=max(max(x[i],x[j]),max(x[k],x[l]));
                    ll uy=max(max(y[i],y[j]),max(y[k],y[l]));
                    ll lx=min(min(x[i],x[j]),min(x[k],x[l]));
                    ll ly=min(min(y[i],y[j]),min(y[k],y[l]));
                    int num=0;
                    for(int m=0;m<n;m++){
                        if(x[m]>=lx && x[m]<=ux && y[m]>=ly && y[m]<=uy) num++;
                    }
                    ll buf=(ux-lx)*(uy-ly);
                    if(num>=K) ans=min(ans,buf);
                }
            }
        }
    }
    cout<<ans<<endl;

}