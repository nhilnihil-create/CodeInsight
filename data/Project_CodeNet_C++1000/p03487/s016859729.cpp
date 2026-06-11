#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll LINF = 1e18;
const int INF = 1e9;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(){
    int N; cin>>N;
    int a[1000001];
    rep(i,1000001)a[i]=0;
    int ans=0;
    rep(i,N){
        int x; cin>>x;
        if(x>N){
            ans++;
            continue;
        }
        a[x]++;
        ans++;
        if(a[x]==x)ans-=x;
    }
    cout<<ans<<endl;
    return 0;
}