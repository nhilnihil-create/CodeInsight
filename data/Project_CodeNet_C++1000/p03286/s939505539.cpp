#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define ve vector
#define chmin(x,y) x = min(x,y)

int main(){
    ll n;
    cin >> n;
    if(n==0)cout << 0 << endl;
    if(n>0){
        ve<ll> s = {};
        ll j = 0;
        while(n >= 1<<j){
            if((n>>j) & 1)s.push_back(1);
            else s.push_back(0);
            j++;
        }
        rep(i,10)s.push_back(0);
        
        rep(i,s.size()-2){
            if(s[i] >= 2){
                s[i+1] += (s[i]- s[i]%2)/2;
                s[i] = s[i]%2;
            }
            if(i%2 != 0){
                s[i+1]+=s[i];
            }
        }
        reverse(s.begin(),s.end());
        bool fl = false;
        rep(i,s.size()){
            if(fl)cout << s[i];
            else{
                if(s[i] == 0)continue;
                else{
                    cout << 1;
                    fl = true;
                }
            }
        }
        cout << endl;
    }
    if(n<0){
        n *= -1;
        ve<ll> s = {};
        ll j = 0;
        while(n >= 1<<j){
            if((n>>j) & 1)s.push_back(1);
            else s.push_back(0);
            j++;
        }
        rep(i,10)s.push_back(0);
        
        rep(i,s.size()-2){
            if(s[i] >= 2){
                s[i+1] += (s[i]- s[i]%2)/2;
                s[i] = s[i]%2;
            }
            if(i%2 == 0){
                s[i+1]+=s[i];
            }
        }
        reverse(s.begin(),s.end());
        bool fl = false;
        rep(i,s.size()){
            if(fl)cout << s[i];
            else{
                if(s[i] == 0)continue;
                else{
                    cout << 1;
                    fl = true;
                }
            }
        }
        cout << endl;
    }
    return 0;
}
