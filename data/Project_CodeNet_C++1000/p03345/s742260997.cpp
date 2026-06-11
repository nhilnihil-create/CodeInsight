#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;
#define rep(i, n) for (ll i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (ll i = (s); i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
const ld pi=3.14159265358979323846;
 
int main() {
    ll a,b,c,k;
    cin>>a>>b>>c>>k;
    ll num=a-b;
    if (k%2==1){
        cout<<(-1)*num<<endl;
    }
    else{
        cout<<num<<endl;
    }
}