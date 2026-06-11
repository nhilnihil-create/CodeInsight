#include <bits/stdc++.h>
#define be(v) (v).begin(),(v).end()
#define pb(q) push_back(q)
typedef long long ll;
using namespace std;
const ll mod=1000000007;
#define doublecout(a) cout<<fixed<<setprecision(10)<<a<<endl;

int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    int n,a,b;
    cin>>n>>a>>b;
    int p[n];
    for(int i=0;i<n;i++)cin>>p[i];
    ll x=0,y=0,z=0;
    for(int i=0;i<n;i++){
        if(a>=p[i])x++;
        else if(b>=p[i])y++;
        else z++;
    }
    cout << (min(x,min(y,z)))<<endl;
    return 0;
}
