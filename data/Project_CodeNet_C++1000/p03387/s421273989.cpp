#include <bits/stdc++.h>  
using namespace std;
using ll = long long int;
using pii = pair<int, int>;
#define rep(i,n) for(int i=0; i<(int)(n); i++)

int main(){
  vector<int> v(3);
  cin>>v[0]>>v[1]>>v[2];
  sort(v.begin(),v.end());
  v[1]-=v[0];v[2]-=v[0];v[0]=0;

  int a=v[1],b=v[2];
  if(a%2==0){cout<<b-a+a/2;}
  else{cout<<a/2+b-a+2;}
}