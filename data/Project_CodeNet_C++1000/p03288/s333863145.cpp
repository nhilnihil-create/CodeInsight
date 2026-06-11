#include<bits/stdc++.h>
using namespace std;
using p=pair<int,int>;
#define int long long
#define rep(i,N) for(int i=0;i<N;i++)

signed main(){
  int R;
  cin>>R;
  if(R<1200)cout<<"ABC"<<endl;
  if(R<2800&&R>=1200)cout<<"ARC"<<endl;
  if(R>=2800)cout<<"AGC"<<endl;
}