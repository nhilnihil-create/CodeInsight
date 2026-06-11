#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define N 100005
#define INF 1000000005
typedef long long ll;
#define ALL(v) (v).begin(),(v).end()
#define SZ(x) int(x.size())
#define IN(a) cin>>(a)
#define OUT(a) cout<<(a)<<endl
typedef pair<int,int> P;
const int MAX = 1000005;
const int MOD = 1000000007;
int main(){
    int n,G;
    cin>>n>>G;
    vector<int>p(n);
    vector<int>c(n);
    REP(i,n)cin>>p[i]>>c[i];
    int ans=INF;
    for(int bit=0;bit<(1<<n);bit++){
        vector<int> S,T;
        REP(i,n){
            if(bit & (1<<i)){
                S.push_back(i);
            }else{
                T.push_back(i);
            }
        }
        int cnt=0;
        int sum=0;
        for(auto a:S){
            cnt+=p[a];
            sum+=p[a]*100*(a+1)+c[a];
        }
        int i=SZ(T)-1;
        while(G>sum){
            int w=min(p[T[i]]-1,(G-sum+100*(T[i]+1)-1)/(100*(T[i]+1)));
            cnt+=w;
            sum+=w*100*(T[i]+1);
            i--;
            if(i<0&&G>sum){
                cnt=INF;
                break;
            }
        }
        ans=min(ans,cnt);
    }
    OUT(ans);
    return 0;
}