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
    vector<int> a(5);
    int k;
    rep(i,0,4)cin>>a[i];
    cin>>k;
    sort(a.begin(),a.end());
    if(a[4]-a[0]<=k) cout<<"Yay!"<<endl;
    else cout<<":("<<endl;
    return 0;
}