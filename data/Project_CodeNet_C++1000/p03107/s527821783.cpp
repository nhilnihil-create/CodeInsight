#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define pii pair<int,int>
const long long MOD=1000000007;

long long mgcd(long long x,long long m){
    if(x==m) return m;
    return mgcd(m,x%m);
}

int main(){
    string s;
    cin>>s;
    stack<char> sta;
    int ans=0;
    rep(i,s.size()){
        if(!sta.empty()){
            char a=sta.top();
            if(s[i]==a) sta.push(s[i]);
            else{
                sta.pop();
                ans++;
            }
        }
        else sta.push(s[i]);
    }
    cout<<2*ans<<endl;
    return 0;
}