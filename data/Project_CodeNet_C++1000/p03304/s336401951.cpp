#include<bits/stdc++.h>
using namespace std;
int main(){
  long double n,m,d;
  cin>>n>>m>>d;
  if(d==0)cout<<fixed<<setprecision(16)<<(m-1)/n<<endl;
  else cout<<fixed<<setprecision(16)<<2*(n-d)*(m-1)/(n*n)<<endl;
}