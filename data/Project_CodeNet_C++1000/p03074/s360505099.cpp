#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n,k;
string s;

int main(){
    cin >> n >> k;
    cin >> s;
    vector<ll> vec;
    if(s[0]=='0') vec.push_back(0);
    for(ll i=0;i<n;){
        ll j=i;
        while(j<n&&s[j]==s[i]) j++;
        vec.push_back(j-i);
        i=j;
    }
    if(s[n-1]=='0') vec.push_back(0);

    vector<ll> cal(vec.size()+1,0);
    for(ll i=0;i<vec.size();i++){
        cal[i+1]=cal[i]+vec[i];
    }

    ll res=0;
    for(ll i=0;i<cal.size();i+=2){
        ll j=i+k*2+1;
        if(j>=cal.size()) j=cal.size()-1;
        res=max(res,cal[j]-cal[i]);
    }
    cout << res << endl;
    return 0;
}  
