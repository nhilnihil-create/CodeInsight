#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
using ll=long long;
int main(){
    int n;
    cin>>n;
    vector<string>s(n);
    int ans=0;
    rep(i,n){
        cin>>s[i];
        rep(j,s[i].size()-1){
            if(s[i][j]=='A'&&s[i][j+1]=='B')ans++;
        }
    }
    int a=0,b=0,ab=0;
    rep(i,n){
        if(s[i][0]=='B'&&s[i][s[i].size()-1]=='A')ab++;
        if(s[i][0]=='B'&&s[i][s[i].size()-1]!='A')b++;
        if(s[i][0]!='B'&&s[i][s[i].size()-1]=='A')a++;
    }
    if(a==0&&b==0&&ab>=2)cout<<ans+ab-1<<endl;
    else cout<<ans+min(ab+a,ab+b)<<endl;
}