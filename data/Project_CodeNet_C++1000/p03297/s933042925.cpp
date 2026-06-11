#include <bits/stdc++.h> 
using namespace std;
using ll = long long;
template<typename T> using v2 = vector<vector<T>>;
template<typename T> inline v2<T> fill(int r, int c, const T& t){ return v2<T>(r, vector<T>(c, t)); }
#define F first
#define S second

void solve(){
    ll a,b,c,d;
    cin>>a>>b>>c>>d;

    if(d<b || a<b){
        cout << "No\n";
    }
    else{
        ll gcd = __gcd(b, d);
        ll max = (b-gcd + (a%b)%gcd);
        if(max <= c){
            cout << "Yes\n";
        }
        else{
            cout << "No\n";
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T; cin >> T;
    for(int i = 0; i < T; ++i){
        solve();
    }
    return 0;
}