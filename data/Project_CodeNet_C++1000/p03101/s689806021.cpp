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
    int H,W,h,w;
    cin>>H>>W>>h>>w;
    int ans=(H-h)*(W-w);
    OUT(ans);
    return 0;
}