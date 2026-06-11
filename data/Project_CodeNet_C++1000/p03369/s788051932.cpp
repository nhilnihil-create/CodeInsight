#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using ll=long long;
using namespace std;

int main(){
    string s;
    cin>>s;
    int num=0;
    rep(i,s.size()) if(s[i]=='o') num++;
    cout<<700+100*num<<"\n";
    return 0;
}