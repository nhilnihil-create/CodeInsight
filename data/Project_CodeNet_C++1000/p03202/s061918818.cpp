#include<bits/stdc++.h>
//using namespace std;
#define rep(i,j,n) for(ll i=(ll)(j);i<(ll)(n);i++)
#define REP(i,j,n) for(ll i=(ll)(j);i<=(ll)(n);i++)
#define per(i,j,n) for(ll i=(ll)(j);(ll)(n)<=i;i--)
#define ll long long
#define ALL(a) (a).begin(),(a).end()
#define disup(A,key) distance(A.begin(),upper_bound(ALL(A),(ll)(key)))
#define dislow(A,key) distance(A.begin(),lower_bound(ALL(A),(ll)(key)))
#define pb push_back
#define mp make_pair
#define endl "\n"
using std::cin;
using std::cout;
using std::vector;
using std::pair;
using std::string;
using std::upper_bound;
using std::lower_bound;
using vi=vector<ll>;
using vii=vector<vi>;
using pii=pair<ll,ll>;
const ll MOD=1e9+7;//998244353;
const int MAX=1e5;
const ll INF=(1ll<<62)-1;
bool judge(int N,vi &A,int X){
    if(X==1){
        rep(i,1,N){
            if(A[i-1]>=A[i]) return 0;
        }
        return 1;
    }
    std::map<int,int,std::greater<int>> num;
    rep(i,1,N){
        if(num.size()==0){
            if(A[i-1]>=A[i]) num[A[i]]++;
        }
        else if(A[i-1]>=A[i]){
            for(auto p:num){
                if(p.first>A[i]) num.erase(p.first);
                else break;
            }
            num[A[i]]++;
            per(j,A[i],1){
                if(num[j]==X){
                    num.erase(j);
                    num[j-1]++;
                }
                else break;
            }
            if(num[0]==1){
                return 0;
            }
        }
    }
    return 1;
}
signed main(){
    int N; cin>>N;
    vi len(N);
    rep(i,0,N) cin>>len[i];
    int left=1,right=N;
    while(left+1<right){
        int mid=(left+right)/2;
        if(judge(N,len,mid)) right=mid;
        else left=mid;
    }
    int ans=right;
    if(judge(N,len,left)) ans=left;
    cout<<ans<<endl;
}
 
 

