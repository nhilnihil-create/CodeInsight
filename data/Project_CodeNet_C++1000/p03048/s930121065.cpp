#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD=1000000007;
#define INF 1LL<<30
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(x) (x).begin(),(x).end()

int main(){
    int R,G,B,N;
    cin>>R>>G>>B>>N;

    int ans=0;
    rep(r,N+1){
        rep(g,N+1){
            if(r==0 && g==0){
                if(N%B==0) ans++;
                continue;
            }
            int tmp=N-r*R-g*G;
            if(tmp%B!=0) continue;
            if(tmp/B>=0) ans++;
        }
    }

    cout<<ans<<endl;
}
