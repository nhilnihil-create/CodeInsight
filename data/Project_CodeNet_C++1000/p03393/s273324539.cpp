#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const ll N=2e6+5,mod=1e9+7;
int main(){
    cin.tie(NULL); cout.tie(NULL);
    ios_base:: sync_with_stdio(false);
    string s;cin>>s;
    if(s.length()<26){
        cout<<s;
        for(char ch='a';ch<='z';ch++)if(s.find(ch)==string::npos)return cout<<ch , 0;
    }
    string t=s;
    bool flg = next_permutation(s.begin(),s.end());
    if(!flg)return cout<<"-1" , 0;

    ll i=0;
    while(i<s.size() && s[i]==t[i])cout<<s[i++];
    cout<<s[i];
}


