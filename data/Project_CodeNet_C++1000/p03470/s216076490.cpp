#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i,n) for(int i=0;i<(n);++i)
#define repi(i,a,b) for(int i=int(a);i<int(b);++i)
#define all(x) (x).begin(), (x).end()
using namespace std;
int main() {
    int n;
    cin>>n;
    int d[n],num[110]={0};
    rep(i,n){
        cin>>d[i];
        num[d[i]]++;
    }
    int cnt=0;
    rep(i,110){
        if(num[i]!=0) cnt++;
    }
    cout<<cnt<<endl;
}