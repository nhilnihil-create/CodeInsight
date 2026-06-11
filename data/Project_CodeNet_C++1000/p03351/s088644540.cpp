#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
#define rep(i,m,n) for(int i=m;i<n;i++)
ll mod=1e9+7;

int main(){
  int a,b,c,d;
  cin>>a>>b>>c>>d;
  if(abs(a-c)<=d || (abs(a-b)<=d && abs(b-c)<=d)){
    cout<<"Yes"<<endl;
  }
  else{
    cout<<"No"<<endl;
  }
}