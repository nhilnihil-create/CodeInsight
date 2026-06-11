//#define _GLIBCXX_DEBUG

#include<bits/stdc++.h>
using namespace std;
const int INF= 1e9+5;
typedef long long ll;

int main(){
  int a,b;
  cin>>a>>b;
  if(b%a==0){
    cout<<a+b<<endl;
  }
else cout<<b-a<<endl;
}