#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;



int main(){
    string s;
    cin >> s;
    ll n=s.size();
    ll l=0;
    ll r=n-1;
    bool flag=true;
    ll res=0;
    while(r>=l){
        if(s[r]==s[l]){
            l++;
            r--;
        }
        else if(s[l]=='x'&&s[r]!='x'){
            l++;
            res++;
        }
        else if(s[l]!='x'&&s[r]=='x'){
            r--;
            res++;
        }
        else if(s[l]!='x'&&s[r]!='x'&&s[l]!=s[r]){
            flag=false;
            break;
        }
    }
    if(!flag) cout << -1 << endl;
    else cout << res << endl;
    return 0;
}  
