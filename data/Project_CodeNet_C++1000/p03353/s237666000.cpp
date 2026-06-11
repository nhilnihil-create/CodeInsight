#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9+7;
int main() {
    string s;
    cin >> s;
    ll k;
    cin >> k;
    ll n=s.size();
    vector<string>ans;
    for(ll i=0;i<n;i++){
        string sumple=s.substr(i,1);
        ans.push_back(sumple);
        ll j=1;
        while(j<5){
            if(i+j>n-1) break;
            sumple.push_back(s[i+j]);
            ans.push_back(sumple);
            j++;
        }
    }
    sort(ans.begin(),ans.end());
    for(ll i=1;i<ans.size();i++){
        if(ans[i]==ans[i-1]){
            ans[i-1]="zzzzzz";
        }
    }
    sort(ans.begin(),ans.end());
    cout << ans[k-1] << endl;
}