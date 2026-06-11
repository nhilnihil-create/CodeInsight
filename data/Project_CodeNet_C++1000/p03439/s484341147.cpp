#include <bits/stdc++.h>
typedef long long ll;
#define rep(i,a,n) for(ll i = a;i < n;i++)
#define rrep(i,a,n) for(ll i = n; i >= a;i--)
#define LINF (ll)1e18
#define INF (int)1e9
#define ll_1e9 (ll)1e9
using namespace std;


int main(){
    ll n;
    cin >> n;
    ll l = 0,r = n,m,i = 0;
    
    string res_0,res_m;

    cout << 0 << endl;
    cin >> res_0;
    if(res_0 == "Vacant") return 0;
    
    while(i++ < 19){
        
        m = (r+l)/2;

        cout << m << endl;
        cin >> res_m;

        if(res_m == "Vacant") break;

        if(m % 2){
            if(res_0 == res_m) r = m;
            else l = m+1;
        }
        else{
            if(res_0 == res_m) l = m;
            else r = m+1;
        }
    }
    return 0;
}
