#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;



int main(){
    ll n;
    cin >> n;
    string s[n];
    ll counta=0,countb=0,countab=0,count=0;
    for(ll i=0;i<n;i++){
        cin >> s[i];
        if(s[i][0]=='B') countb++;
        if(s[i][s[i].size()-1]=='A') counta++;
        if(s[i][0]=='B'&&s[i][s[i].size()-1]=='A') countab++;
        for(ll j=0;j<(ll)s[i].size()-1;j++){
            if(s[i][j]=='A'&&s[i][j+1]=='B') count++;
        }
    }
    if(countab>0&&countab==counta&&countab==countb) cout << count+counta-1 << endl;
    else cout << count+min({counta,countb,n-1}) << endl;
    return 0;
}  
