#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;cin>>n;
  int k;cin>>k;
  vector<int>a(n,0);
  int tmp;
  for(int i=0;i<n;i++){
    cin>>tmp;
    a.at(tmp-1)++;
  }
  tmp=0;
  vector<int>b;
  for(int i=0;i<n;i++){
    if(a.at(i)!=0){
      tmp++;
      b.push_back(a.at(i));
    }
  }
  tmp-=k;
  sort(b.begin(),b.end());
  int ans=0;
  for(int i=0;i<tmp;i++){
    ans+=b.at(i);
  }
  cout <<ans<<endl;
}