#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
using ll=long long;

int main(){
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    vector<int>n;
    n.push_back(a);
    n.push_back(b);
    n.push_back(c);
    n.push_back(d);
    bool ok=true;
    if(count(n.begin(),n.end(),1)==0)ok=false;
    if(count(n.begin(),n.end(),9)==0)ok=false;
    if(count(n.begin(),n.end(),7)==0)ok=false;
    if(count(n.begin(),n.end(),4)==0)ok=false;
    cout<<(ok?"YES":"NO")<<endl;
    return 0;
}