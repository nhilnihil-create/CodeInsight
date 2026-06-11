#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
const long long INF = 1e15;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    string s;
    cin >> s;
    ll n = s.size();
    ll ans = 0;
    ll na = 0;
    for(ll i = 0; i < n-1; i++){
        if(s[i] == 'A') na++;
        else if(s[i] == 'B'){
            string t = s.substr(i,2);
            if(t == "BC"){
                ans += na;
                i++;
            } else na = 0;
        } else na = 0;
    }
    cout << ans << endl;
    return 0;
}