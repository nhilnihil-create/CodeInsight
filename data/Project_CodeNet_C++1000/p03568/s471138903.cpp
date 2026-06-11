#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vec;
typedef pair<ll, ll> P;

int main(){
    int n, a, b;
        cin >> n;
    vec v(n); 
    ll ans = pow(3.0, n), cnt=1;
            for(int i=0; i<n; i++) cin >>  v.at(i);
            for(int i=0; i<n; i++)
                if(v.at(i)%2==0) cnt *= 2;
        cout << ans - cnt << endl;
        
}