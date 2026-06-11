#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll=long long;
using P=pair<int,int>;
int main() {
    int a,b,c,x,y;
    cin>>a>>b>>c>>x>>y;
    int aplan,bplan,abplan,waste;
    //all a
    if(2*c<b) aplan=a*x+c*y*2;
    else aplan=a*x+b*y;
    //all b
    if(2*c<a) bplan=b*y+c*x*2;
    else bplan=a*x+b*y;
    // ab
    if(x>y) abplan=2*c*y+a*(x-y);
    else abplan=2*c*x+b*(y-x);
    //waste
    waste=2*c*max(x,y);
    cout<<min(min(waste,aplan),min(bplan,abplan));

}