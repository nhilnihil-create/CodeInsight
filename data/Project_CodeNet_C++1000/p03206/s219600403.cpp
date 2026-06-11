#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define N 105
#define INF 1000000000
typedef long long ll;
#define ALL(v) (v).begin(),(v).end()
#define SZ(x) int(x.size())
#define IN(a) cin>>(a)
#define OUT(a) cout<<(a)<<endl
typedef pair<int,int> P;
const int MAX = 100005;
const int MOD = 1000000007;
int main(){
    int d;
    cin>>d;
    d=abs(d-25);
    string s="Christmas";
    string t=" Eve";
    REP(i,d)s=s+t;
    OUT(s);
    return 0;
}