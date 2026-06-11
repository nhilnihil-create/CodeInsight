#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<n; i++)
#define PI 3.14159265359
#define INF 1000100100//000000000
#define MOD 1000000007
#define all(x) (x).begin(),(x).end()
typedef long long ll;
#define P pair<int, int>
#define PP pair<P,P>
#define T tuple<int,int,int> //tuple<ll,ll,ll>
#define pr(x) cout << x << endl;
using namespace std;

int main(){
 int n,a,b; cin >> n >> a >> b;
 cout << min(n*a,b) << endl;
return 0;
}
