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
    int m=0;
    int sum=0;
    rep(i,n){
        int l; cin >> l;
        m=max(m,l);
        sum+=l;
    }
    if(sum-m>m) cout << "Yes" << endl;
    else cout << "No" << endl;
return 0;
}
