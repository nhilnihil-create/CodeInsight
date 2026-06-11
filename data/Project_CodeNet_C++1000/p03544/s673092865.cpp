#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  int N;
  cin>>N;
  vector<ll> a(N+1);
  a.at(0)=2;
  a.at(1)=1;
  for(int i=2; i<=N; i++){
    a.at(i)=a.at(i-1)+a.at(i-2);
  }
  cout<<a.at(N)<<endl;
}