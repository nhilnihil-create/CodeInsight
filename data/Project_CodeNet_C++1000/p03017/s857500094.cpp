#include <bits/stdc++.h>
 
using namespace std;
using ll = long long;
	
ll mod = 1e9 + 7;
 
int main(){
	ll n, a, b, c, d; cin >> n >> a >> b >> c >> d;
    string s; cin >> s;
    a--;b--;c--;d--;
    for(ll i = a + 1; i < c; ++i){
        if(s[i] == '#' && s[i + 1] == '#'){
            cout << "No";
            return 0;
        }
    }
    for(ll i = b + 1; i < d; ++i){
        if(s[i] == '#' && s[i + 1] == '#'){
            cout << "No";
            return 0;
        }
    }
    if(d > c){
        cout << "Yes";
    }else{
        for(ll i = b; i <= d; ++i){
            if(s[i] == '.' && s[i - 1] == '.' && s[i + 1] == '.'){
                cout << "Yes";
                return 0;
            }
        }
        cout <<"No";
    }
    return 0;
}
