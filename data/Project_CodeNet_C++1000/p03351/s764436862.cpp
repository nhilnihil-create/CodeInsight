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
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    if(max(a,c)-min(a,c)<=d) cout<<"Yes"<<endl;
    else if(max(a,b)-min(a,b)<=d&&max(b,c)-min(b,c)<=d) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    return 0;
}