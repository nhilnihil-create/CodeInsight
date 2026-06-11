#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
 
long long gcd(long long a, long long b){
    if(b==0) return a;
    return gcd(b,a%b);
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(20);
 
    ll q;
    cin>>q;
    while(q--){
        ll a,b,c,d;
        cin>>a>>b>>c>>d;
        if(a<b || b>d){
            cout << "No\n";
            continue;
        }
        if(b-1<=c){
            cout << "Yes\n";
            continue;
        }
        ll g = gcd(b,d);
        ll t = (b - a%g + g-1)/g*g + a%g - g;
        if(c>=t){
            cout << "Yes\n"; 
        }
        else cout << "No\n";

    }
    
}