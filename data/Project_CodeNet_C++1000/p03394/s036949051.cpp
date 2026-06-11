#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
const int INF=1e9,MOD=1e9+7;
const ll LINF=1e18;
using namespace std;
#define int long long
//template

//main
signed main(){
  int N;cin>>N;int n=N;
  std::vector<int> ans,awa;
  for(int i=1;i<=60;i++)if(i%2==0||i%3==0||i%5==0)awa.push_back(i);
  int k;
  int S=awa.size();
  if(N>=S){
    for(k=0;N>=S;k++){
      N-=S;
      for(int p:awa)ans.push_back(p+60*k);
    }
    while(N--)ans.push_back(60*++k);
    for(int p:ans)cout<<p<<" ";cout<<endl;
  }
  else{
    if(N==3){cout<<"2 5 63"<<endl;return 0;}
    if(N==4){cout<<"2 5 20 63"<<endl;return 0;}
    if(N==5){cout<<"2 3 8 9 14"<<endl;return 0;}
    for(int k=0;6*k+10<=30000&&N>=6;k+=2){
      ans.push_back(6*k+2);
      ans.push_back(6*k+3);
      ans.push_back(6*k+4);
      ans.push_back(6*k+8);
      ans.push_back(6*k+9);
      ans.push_back(6*k+10);
      N-=6;
    }
    for(int k=1;6*k<=30000&&N>0;k++){
      ans.push_back(6*k);
      N--;
    }
    for(int p:ans)cout<<p<<" ";cout<<endl;
  }
}
