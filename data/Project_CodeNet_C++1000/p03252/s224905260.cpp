#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using product = pair<ll,ll>;
using vvll = vector<vector<ll>>;
using vll = vector<ll>;

int main()
{
    string s,t;
    cin>>s>>t;
    vector<char> shiftS(26,' ');// tのアルファベットはsのどのアルファベットに対応する？
    vector<char> shiftT(26,' ');// 逆
    string res="Yes";
    ll length=s.size();
    for(ll i=0;i<length;i++)
    {
        ll numS=s[i]-'a';
        ll numT=t[i]-'a';
        if(shiftS[numS]!=t[i] && shiftS[numS]!=' ')
        {
            res="No";break;
        }
        if(shiftT[numT]!=s[i] && shiftT[numT]!=' ')
        {
            res="No";break;
        }
        shiftS[numS]=t[i];
        shiftT[numT]=s[i];
    }
    cout<<res;
}