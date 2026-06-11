#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return true; } return false; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return true; } return false; }
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define mp make_pair
#define si(x) int(x.size())
const int mod=1000000007,MAX=100005,INF=1<<30;

ll dp[MAX];

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N;cin>>N;
    vector<vector<ll>> A(N,vector<ll>(N));
    
    for(int i=0;i<N;i++) for(int j=0;j<N;j++) cin>>A[i][j];
    
    for(int bit=0;bit<(1<<N);bit++){
        for(int i=0;i<N;i++){
            for(int j=i+1;j<N;j++){
                if((bit&(1<<i))&&(bit&(1<<j))){
                    dp[bit]+=A[i][j];
                }
            }
        }
    }
    
    dp[0]=0;
    for(int bit=0;bit<(1<<N);bit++){
        for(int S=bit;;S=(S-1)&bit){
            chmax(dp[bit],dp[S]+dp[bit^S]);
            if(S==0) break;
        }
    }
    
    cout<<dp[(1<<N)-1]<<endl;
}

