#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define all(a) a.begin(),a.end()
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define Rep(i,n,m) for(int i=(int)(n);i<(int)(m);i++)

//library----------------------------------------------


int main(){
    int a,b,c; cin >>a>>b>>c;
    int max = a;
    if(max<b) max=b;
    if(max<c) max=c;
    int ans = max*10+(a+b+c-max);
    printf("%d",ans);
    return 0;
}