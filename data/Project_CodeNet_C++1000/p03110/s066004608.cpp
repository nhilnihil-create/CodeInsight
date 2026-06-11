#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<n; i++)
#define PI 3.14159265359
#define INF 1000100100
#define all(x) (x).begin(),(x).end()
typedef long long ll;
#define P pair<ll, ll>
#define PP pair<P,P>
using namespace std;

int main(){
    int n; cin >> n;
    double ans=0;
    rep(i,n){
        double x; string s; cin >> x >> s;
        if(s=="JPY") ans+=x;
        else ans+=x*380000.0;
    }
    cout << ans << endl;
return 0;
}

