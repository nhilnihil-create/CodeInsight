#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define inf 1001001001001001001
#define mod 1000000007
#define mod2 998244353
#define pi acos(-1)
#define all(v) v.begin(),v.end()
int main(){
    vector<char>c={'A','B','C','D','E','F'};
    char x,y;cin>>x>>y;
    int X,Y;
    rep(i,6){
        if(x==c.at(i)){
            X=i;
        }
        if(y==c.at(i)){
            Y=i;
        }
    }
    if(X<Y){
        cout<<"<"<<endl;
    }else if (X==Y){
        cout<<"="<<endl;
    }else{
        cout<<">"<<endl;
    }
}
