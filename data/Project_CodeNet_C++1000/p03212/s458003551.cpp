#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll,ll>;
using vvll = vector<vector<ll>>;
using vll = vector<ll>;
using vstr = vector<string>;

ll N,K;
vll d;

vector<char> num{'3','5','7'};

bool ok(string s)
{
    bool seven=false;
    bool five=false;
    bool three=false;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='7')seven=true;
        if(s[i]=='5')five=true;
        if(s[i]=='3')three=true;
    }
    return seven && five && three;
}

void dfs(vstr& enm,string cur)
{
    if(cur!="")if(N<stol(cur))return;
    if(ok(cur))enm.emplace_back(cur);
    for(int i=0;i<3;i++)
    {
        string next=cur+num[i];
        dfs(enm,next);
    }
}

int main()
{
    cin>>N;

    vstr enm;
    dfs(enm,"");

    cout<<enm.size()<<endl;
}