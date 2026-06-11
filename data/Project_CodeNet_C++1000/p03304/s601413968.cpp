#include <bits/stdc++.h>
#define be(v) (v).begin(),(v).end()
#define pb(q) push_back(q)
typedef long long ll;
using namespace std;
const ll mod=1000000007;
#define doublecout(a) cout<<fixed<<setprecision(10)<<a<<endl;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    double n,m,d;
    cin>>n>>m>>d;
    doublecout(((d)?2:1)*(m-1)*(n-d)/(n*n));
    return 0;
}
