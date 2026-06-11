#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <cmath>
#define rep(i,cc,n) for(int i=cc;i<=n;++i)
#define drep(i,cc,n) for(int i=cc;i>=n;--i)
typedef long long ll;
using namespace std;
int main(){
    string s;
    cin>>s;
    bool flag=false;
    int a=0,b=0,c=0;
    rep(i,0,2){
        if(s[i]=='a') a++;
        if(s[i]=='b') b++;
        if(s[i]=='c') c++;
        if(a==b&&b==c) flag = true; 
    }
    if(flag) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    return 0;
}