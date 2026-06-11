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
    int n;
    cin>>n;
    vector<vector<char>>s(n,vector<char>(n));
    REP(i,n){
        REP(j,n)cin>>s[i][j];
    }
    int ans=0;
    REP(i,n){
        bool f=true;
        REP(j,n){
            int y=(2*n-i+j-1)%n;
            REP(k,n){
                if(s[j][k]!=s[(j-y+k+n)%n][y]){
                    f=false;
                    break;
                }
            }
            if(!f)break;
        }
        if(f)ans+=n;
    }
    OUT(ans);
    return 0;
}