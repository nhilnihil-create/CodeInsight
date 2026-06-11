#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define N 105
#define INF 100000000
typedef long long ll;
#define ALL(v) (v).begin(),(v).end()
#define SZ(x) int(x.size())
#define IN(a) cin>>(a)
#define OUT(a) cout<<(a)<<endl
typedef pair<int,int> P;
const int MAX = 100005;
const int MOD = 1000000007;

int n,A,B,C;
vector<int>l(8);
int dfs(int cnt=0,int a=0,int b=0,int c=0){
    if(cnt==n){
        return (min({a,b,c})>0)?abs(a-A)+abs(b-B)+abs(c-C)-30:INF;
    }
    return min({dfs(cnt+1,a,b,c),dfs(cnt+1,a+l[cnt],b,c)+10,dfs(cnt+1,a,b+l[cnt],c)+10,dfs(cnt+1,a,b,c+l[cnt])+10});
}
int main(){
    cin>>n>>A>>B>>C;
    REP(i,n)IN(l[i]);
    OUT(dfs());
    return 0;
}