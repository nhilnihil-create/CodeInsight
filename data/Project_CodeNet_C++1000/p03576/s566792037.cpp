#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<utility>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<functional>
#include<math.h>
#include<random>
#include <bitset>
#include <cassert>
#include <complex>
using namespace std;
//#define N (1000000000+7)
//#define N 998244353
#define INF 1e16
typedef long long ll;
typedef pair<ll,ll> P;
typedef pair<int,P> Q;

int main() {
    int n,k;
    cin>>n>>k;
    vector<P>p(n);
    vector<ll>X,Y;
    for(int i=0;i<n;i++){
        ll x,y;
        cin>>x>>y;
        p[i]=P(x,y);
        X.push_back(x);
        Y.push_back(y);
    }
    sort(X.begin(),X.end());
    sort(Y.begin(),Y.end());
    ll ans = 1LL*(X[X.size()-1]-X[0])*(Y[Y.size()-1]-Y[0]);
    for(int x1=0;x1<n;x1++){
        for(int x2=x1+1;x2<n;x2++){
            for(int y1=0;y1<n;y1++){
                for(int y2=y1+1;y2<n;y2++){
                    int num = 0;
                    ll lx = X[x1],rx = X[x2];
                    ll by = Y[y1],uy = Y[y2];
                    for(int i=0;i<n;i++){
                        if(lx<=p[i].first&&p[i].first<=rx&&by<=p[i].second&&p[i].second<=uy){
                            num++;
                        }
                    }
                    if(num>=k){
                        ans = min(ans,1LL*(rx-lx)*(uy-by));
                    }
                }
            }
        }
    }
    cout<<ans<<endl;
}
