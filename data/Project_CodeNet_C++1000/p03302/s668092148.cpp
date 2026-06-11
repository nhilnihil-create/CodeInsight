#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int INF = 1<<30;

int main(){
  int a, b;cin>>a>>b;
  if(a+b==15)cout<<'+'<<endl;
  else if(a*b==15)cout<<'*'<<endl;
  else cout<<'x'<<endl;
}