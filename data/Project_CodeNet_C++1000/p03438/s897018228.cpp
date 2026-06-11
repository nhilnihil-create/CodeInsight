#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin>>n;
  vector<int> a(n);
  vector<int> b(n);
  for(int i=0;i<n;i++)
    cin>>a.at(i);
  for(int i=0;i<n;i++)
    cin>>b.at(i);
  int64_t p=0;
  int64_t m=0;
  for(int i=0;i<n;i++){
    if(b.at(i)-a.at(i)>0)
      p+=(b.at(i)-a.at(i))/2;
    else
      m+=a.at(i)-b.at(i);
  }
  cout<<(p>=m?"Yes":"No")<<endl;
}