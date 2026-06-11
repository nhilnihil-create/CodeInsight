#include <bits/stdc++.h>
using namespace std;
long long i,j,a,b,c,x,y,z,k;
string s;
int main(){
  cin>>a>>b>>c>>k;
  if(abs(a-b)>pow(10,18))return cout<<"Unfair",0;
  if(k&1)cout<<-1*(a-b);
  else cout<<(a-b);
}