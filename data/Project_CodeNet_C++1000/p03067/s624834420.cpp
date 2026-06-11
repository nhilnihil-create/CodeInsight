#include <bits/stdc++.h>
using namespace std;
int main(){
int a,b,c;
  cin>>a>>b>>c;
  if(a>b){
   int tmp=a;
    a=b;
    b=tmp;
  }
  if(a<c&&c<b)cout<<"Yes"<<endl;
  else cout<<"No"<<endl;
}