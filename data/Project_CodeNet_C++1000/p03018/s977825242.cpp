#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int main(){
    cin.tie(NULL); cout.tie(NULL);
    ios_base:: sync_with_stdio(false);
    string s;cin>>s;
    ll n=s.size() , ans = 0;
    string str="";
    for(ll i=0;i<n;i++){
        if(s[i]=='A' || s[i]=='C')str+=s[i];
        else{
            if(i+1<n && s[i+1]=='C')str+="D",i++;
            else str+='C';
        }
    }
    n=str.size();
    for(ll i=0,cnt=0;i<n;i++){
        if(str[i]=='A')cnt++;
        else if(str[i]=='C')cnt=0;
        else{
            ans+=cnt;
        }
    }
    cout<<ans;
}


