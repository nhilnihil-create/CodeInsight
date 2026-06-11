//#define _GLIBCXX_DEBUG

#include<bits/stdc++.h>
using namespace std;
const int INF= 1e9+5;
typedef long long ll;

int main(){
  int a,b,c,d;
  cin>>a>>b>>c>>d;
  if(abs(c-a)<=d || (abs(b-a)<=d) && (abs(c-b)<=d)){
    cout<<"Yes"<<endl;
  }
  else cout<<"No"<<endl;
}