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
    string s;
    cin>>s;
    int n=0;
    int k=7;
    REP(i,SZ(s)){
        if(i==4||i==7)continue;
        n+=(s[i]-'0')*pow(10,k);
        k--;
    }
    if(n>20190430)OUT("TBD");
    else OUT("Heisei");
    return 0;
}