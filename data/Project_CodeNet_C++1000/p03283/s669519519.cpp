#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD=1000000007;
#define INF 1LL<<30
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(x) (x).begin(),(x).end()

int cnt[510][510];
int N,M,Q;

int main(){
    cin>>N>>M>>Q;
    rep(i,M){
        int L,R;
        cin>>L>>R;
        cnt[L][R]++;
    }
    for(int L=1;L<N+1;L++){
        for(int R=2;R<N+1;R++){
            cnt[L][R]+=cnt[L][R-1];
        }
    }

    while(Q--){
        int p,q;
        cin>>p>>q;
        int ans=0;
        for(int L=p;L<q+1;L++) ans+=cnt[L][q];
        cout<<ans<<endl;
    }
}


 