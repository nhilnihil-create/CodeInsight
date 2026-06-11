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

int main(){
    int n;
    cin>>n;
    double ans=0;
    REP(i,n){
        double x;
        string u;
        cin>>x>>u;
        if(u=="JPY"){
            ans+=x;
        }else{
            ans+=(double)x*380000.0;
        }
    }
    printf("%.10lf\n",ans);
    return 0;
}