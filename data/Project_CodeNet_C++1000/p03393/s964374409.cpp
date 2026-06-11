#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
using namespace std;
using ll = long long;

#define rep(i,n) for(ll i=0;i<ll(n);i++)
#define YESNO(T) if(T){cout<<"YES"<<endl;}else{cout<<"NO"<<endl;}
#define yesno(T) if(T){cout<<"yes"<<endl;}else{cout<<"no"<<endl;}
#define YesNo(T) if(T){cout<<"Yes"<<endl;}else{cout<<"No"<<endl;}

const ll INF = 1LL << 60;
const ll MOD = 1e9 + 7;
const double pi = 3.14159265358979;



int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    string s;
    cin >> s;

    ll n = s.size();

    if (n != 26){
        vector<bool> m(26,false);
        for (ll i = 0;i < n;i++){
            m[s[i] - 'a'] = true;
        }

        for (ll i = 0; i < 26; i++){
            if (!m[i]){
                char x = 'a' + i;
                cout << s << x << endl;
                break;
            }
        }
    }
    else if (s == "zyxwvutsrqponmlkjihgfedcba"){
        cout << -1 << endl;
    }
    else{
        vector<bool> m(26,false);
        ll c = 0;
        ll j = 0;
        for (ll i = 25; i >= 1; i--){
            if (s[i] < s[i-1]){
                m[s[i] - 'a'] = true;
            }
            else{
                m[s[i] - 'a'] = true;
                m[s[i-1] - 'a'] = true;
                c = s[i-1] - 'a';
                j = i-1;
                //cout << c << endl;
                //cout << j << endl;
                break;
            }
        }

        /*for (ll i = 0; i < 26; i++){
            if (m[i]){
                cout << i << endl;
            }
        }
        char x = s[c];
        cout << x << endl;*/

        for (ll i = c+1; i < 26; i++){
            if (m[i]){
                s[j] = 'a' + i;
                //cout << s[c] << endl; 
                break;
            }
        }
        
        for (ll i = 0; i <= j; i++){
            cout << s[i];
        }
        cout << endl;
    }
}