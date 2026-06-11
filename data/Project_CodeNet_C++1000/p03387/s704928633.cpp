#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
#define rep(i,m,n) for(int i=m;i<n;i++)
ll mod=1e9+7;

int main(){
  int a,b,c;
  cin>>a>>b>>c;
  int d[3]={a,b,c};
  sort(d,d+3);
  if((d[2]-d[0]+d[2]-d[1])%2==0){
    cout<<(d[2]-d[0]+d[2]-d[1])/2<<endl;
  }
  else{
    cout<<(d[2]-d[0]+d[2]-d[1]+3)/2<<endl;
  }
}