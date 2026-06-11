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
    char a; cin >> a;
    char ans;
    if(a=='A') ans='T';
    if(a=='T') ans='A';
    if(a=='G') ans='C';
    if(a=='C') ans='G';
    cout << ans << endl;
return 0;
}
