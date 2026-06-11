#include <bits/stdc++.h>

using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define ll long long int
#define INF 1000000007
// cin.eof() 入力個数の問題
int main(){
ll n,a,b,c,d,e;
cin>>n>>a>>b>>c>>d>>e;
ll A=min({a,b,c,d,e});
if(n%A==0){
cout<<n/A+4<<endl;
  
}else{
cout<<n/A+5<<endl;
}
  return 0;
}
