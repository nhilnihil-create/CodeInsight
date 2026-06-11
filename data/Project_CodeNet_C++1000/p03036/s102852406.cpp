#include<bits/stdc++.h>
using namespace std;
using p=pair<int,int>;
#define int long long
#define rep(i,N) for(int i=0;i<N;i++)

signed main(){
  int R,D,X;
  cin>>R>>D>>X;
  rep(i,10){
    X=R*X-D;
    cout<<X<<endl;
  }
}