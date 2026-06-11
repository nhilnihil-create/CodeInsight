#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<string>
#include<stack>
#include<functional>
#include<queue>
#include<vector>
#include<algorithm>
#include<iomanip>
#include<utility>
#include<set>
#include<unordered_set>
#include<map>
#include<unordered_map>
typedef long long int ll;
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REP(i,n) for(int i=0;i<signed(n);i++)
#define EREP(i,n) for(int i=1;i<=signed(n);i++)
#define ALL(a) (a).begin(),(a).end()
using namespace std;
//#define EVEL 1
#ifdef EVEL
#define DEB(X) cout << #X <<":" <<X<<" " ;
#define TF(f) f ? cout<<"true  " : cout<<"false ";
#define END cout<<"\n";
#else
#define DEB(X) {}
#define TF(f) {}
#define END {}
#endif
const ll MOD = 1000000007;
const ll INF = 9e14;
typedef std::pair<ll,ll> P;
struct edge{ int to,cost; };
#define VMAX 100000

ll N,M,X,K,Q;
ll A,B,C,D;

ll ans;
bool F=false;
string S,T,U;
int main(){
    cin>>A>>B>>C>>D;
    cout<<A+((C-A)-(D-B))<<" "
        <<B+((C-A)+(D-B))<<" "
        <<A-(D-B)<<" "
        <<B+(C-A)<<endl;
}