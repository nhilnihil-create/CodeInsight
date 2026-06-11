#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
  int n;
  cin>>n;
  vector<int>d(n);
  vector<int>freq(200,0);
  rep(i,n){
    cin>>d[i];
    freq[d[i]]++;
  }
  int cnt=0;
  rep(i,200)
    if(freq[i]>=1)cnt++;
  cout<<cnt<<endl;
  return 0;
  
}