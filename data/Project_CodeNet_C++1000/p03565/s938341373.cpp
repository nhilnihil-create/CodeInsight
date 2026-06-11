#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9+7;

#define debug(...)                                                    \
  std::cerr << "LINE: " << __LINE__ << "  [" << #__VA_ARGS__ << "]:", \
      debug_out(__VA_ARGS__)

void debug_out() { std::cerr << std::endl; }

template <typename Head, typename... Tail>
void debug_out(Head h, Tail... t) {
  std::cerr << " " << h;
  if (sizeof...(t) > 0) std::cout << " :";
  debug_out(t...);
}

int main() {
    string s,t;
    cin >> s >> t;
    ll n=t.size();
    ll x=s.size();
    if(x<n){
        cout << "UNRESTORABLE" << endl;
        return 0;
    }
    vector<ll>check(51,MOD);
    for(ll i=x-n;i>=0;i--){
        bool judge=true;
        for(ll j=0;j<n;j++){
            if(s[i+j]!='?'&&s[i+j]!=t[j]){
                judge=false;
            }
        }
        if(judge){
            check[i]=i;
        }
    }
    sort(check.begin(),check.end());
    ll cnt=0;
    for(ll i=0;i<51;i++){
        if(check[i]==MOD) break;
        cnt++;
    }
    if(cnt==0){
        cout << "UNRESTORABLE" << endl;
        return 0;
    }
    vector<string>S(cnt,"");
    for(ll k=0;k<cnt;k++){
        string sumple="";
        for(ll i=0;i<x;i++){
            if(check[k]==i){
                for(ll j=0;j<n;j++){
                debug(t[j]);
                    sumple.push_back(t[j]);
                }
                i+=n;
            }
            
            if(i>=x)break;

            if(s[i]=='?'){
                sumple.push_back('a');
            }
            else {
            debug(s);
            	debug(s[i]);
                sumple.push_back(s[i]);
            }
          std::cerr<<sumple<<"\n";
        }
        S[k]=sumple;
    }
    sort(S.begin(),S.end());
    cout << S[0] << endl;
}
