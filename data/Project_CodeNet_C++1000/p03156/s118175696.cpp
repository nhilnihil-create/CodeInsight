#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
using ll=long long;
int main(){
    int n,a,b;
    cin>>n>>a>>b;
    vector<int>p(n);
    rep(i,n)cin>>p[i];
    int c1=0,c2=0,c3=0;
    rep(i,n){
        if(p[i]<=a)c1++;
        else if(p[i]>=b+1)c3++;
        else c2++;
    }
    cout<<min({c1,c2,c3})<<endl;
    return 0;
}
