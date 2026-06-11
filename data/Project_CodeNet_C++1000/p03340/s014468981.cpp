#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define N 367
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
    vector<int>a(n);
    REP(i,n)IN(a[i]);
    int j=1;
    ll cnt=0;
    int tmp=a[0];
    REP(i,n){
    while(j<n&&(tmp+a[j])==(tmp^a[j])){
        tmp^=a[j];
        j++;
    }
    cnt+=j-i;
    tmp^=a[i];    
    }
    OUT(cnt);
    return 0;
}