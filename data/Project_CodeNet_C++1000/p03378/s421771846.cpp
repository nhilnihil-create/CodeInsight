#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
  int n,m,x;
  cin>>n>>m>>x;
  vector<int> a(n+1);
  for(int i=0;i<m;i++){
    int b;
    cin>>b;
    a[b]++;
  }
  int c=x;
  int cost0=0;
  while(c!=0){
    c--;
    cost0+=a[c];
  }
  int d=x;
  int costn=0;
  while(d!=n){
    d++;
    costn+=a[d];
  }
  cout<<min(cost0,costn)<<endl;
}