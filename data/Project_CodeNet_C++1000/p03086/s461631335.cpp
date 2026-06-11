#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9+7;
int main() {
    string s;
    cin >> s;
    ll ans=0;
    vector<ll>num;
    for(ll i=0;i<s.size();i++){
        if(s[i]=='A'||s[i]=='C'||s[i]=='G'||s[i]=='T'){
            num.push_back(i);
        }
    }
    ll sum=1;
    if(num.size()==0){
        cout << 0 << endl;
        return 0;
    }
    for(ll i=0;i<num.size()-1;i++){
        if(num[i]==num[i+1]-1){
            sum++;
        }
        else {
            ans=max(ans,sum);
            sum=1;
        }
    }
    ans=max(ans,sum);
    cout << ans << endl;
}