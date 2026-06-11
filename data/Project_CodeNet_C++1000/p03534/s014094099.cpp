#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,n)   FOR(i,0,n)
#define pb emplace_back
typedef long long ll;
typedef pair<int,int> pint;

int cnt[3];
int main(){
    string s;
    cin>>s;
    rep(i,s.size()){
        ++cnt[s[i]-'a'];
    }
    int mx=*max_element(cnt,cnt+3);
    int mn=*min_element(cnt,cnt+3);
    if(mx-mn<=1) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    return 0;
}