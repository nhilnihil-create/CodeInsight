#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<n; i++)
#define PI 3.14159265359
#define INF 1000100100
#define MOD 1000000007
#define all(x) (x).begin(),(x).end()
typedef long long ll;
#define P pair<int, int>
#define PP pair<P,int>
#define T tuple<int,int,int> 
using namespace std;

int main(){
    int n; cin >> n;
    vector<int> p(n);
    rep(i,n) cin >> p[i];
    sort(all(p));
    reverse(all(p));
    int ans=0;
    rep(i,n) ans+=p[i];
    cout << ans-p[0]/2 << endl;
return 0;
}
