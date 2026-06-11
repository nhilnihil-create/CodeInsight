#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll=long long;
using P=pair<int,int>;
int main() {
    int a,b,c,x,y;
    cin>>a>>b>>c>>x>>y;
    int mi=1000000000;
    for(int i=0;i<=2*(x+y);i+=2){
        int p=max(x-i/2,0);
        int q=max(y-i/2,0);
        mi=min(mi,p*a+q*b+i*c);
    }
    cout<<mi<<endl;
}