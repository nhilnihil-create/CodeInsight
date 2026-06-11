#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,x,y) for(int i=x;i<y;i++)


int main (){
    ll a,b,c;
  cin>>a>>b>>c;
    if(b-a+1<=c*2){
        rep(i,a,b+1)cout<<i<<endl;
        return 0;
    }
    rep(i,a,a+c)
      cout << i<< endl;
    rep(i,b-c+1,b+1)
      cout << i<< endl;
    return 0;
}

