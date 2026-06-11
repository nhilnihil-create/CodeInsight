#include <bits/stdc++.h>
#include <cctype>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
using ll = long long;
using p = pair<int,int>;
using Graph = vector<vector<int>>;
int main(int argc, const char * argv[]) {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int a,b;
    cin>>a>>b;
    string s;
    cin>>s;
    bool flag=true;
    rep(i,a){
        if(s[i]=='-')flag=false;
    }
    if(s[a]!='-')flag=false;
    for(int i=a+1;i<(a+b+1);i++){
        if(s[i]<'0'||s[i]>'9')flag=false;
    }
    if(flag)cout<<"Yes"<<endl;
    else cout<<"No"<<endl;

    return 0;
}