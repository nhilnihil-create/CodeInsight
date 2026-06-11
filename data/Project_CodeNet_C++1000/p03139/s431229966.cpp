#include<bits/stdc++.h>
#define V vector
#define VI vector<int>
#define VVI vector<vector<int>>
#define REP(i,n) for(ll i=0;i<(n);i++)
#define FOR(i,m,n) for(ll i=m;i<n;i++)
#define MOD 1000000007
#define INF 1e9
#define F first
#define S second
#define All(x) (x).begin(),(x).end()
typedef long long ll;
const double PI = acos(-1);
using namespace std;

int main(void){
    int N,A,B;cin>>N>>A>>B;
    cout<<min(A,B)<<" "<<max(0,A+B-N)<<endl;
}


