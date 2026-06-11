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
using namespace std;
#define N (1000000000+7)
#define M (998244353)
#define INF 1e16
typedef long long ll;
typedef pair<ll,ll> P;
typedef pair<P,ll>Q;

int main(void){
    int n,m;
    cin>>n>>m;
    vector<P>p(m);
    for(int i=0;i<m;i++){
        ll a,b;
        cin>>a>>b;
        p[i].first = b;
        p[i].second = a;
    }
    sort(p.begin(),p.end());
    int ans = 0;
    ll t = 1;
    for(int i=0;i<m;i++){
        if(t<=p[i].second){
            ans++;
            t = p[i].first;
        }
    }
    cout<<ans<<endl;
    return 0;
}