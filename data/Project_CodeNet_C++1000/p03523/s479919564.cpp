#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    string s;cin>>s;
    string t="AKIHABARA";
    if(s.size()>t.size())return cout<<"NO" , 0;
    for(ll i=0;i<(ll)t.size();i++){
        if(s.size()<i+1){
            if(t[i]=='A')continue;
            cout<<"NO";
            return 0;
        }

        if(s[i]==t[i])continue;
        if(t[i]!='A')return cout<<"NO" , 0;

        s = s.substr(0,i) + "A" + s.substr(i);
    }
    cout<<"YES";
}