#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin>>n;
  vector<int> b(n);
  for(int i=0;i<n;i++)
    cin>>b.at(i);
  vector<int> a;
  for(int s=n;s>0;s--){
    int p=s;
    for(int i=0;i<s;i++)
      p=(b.at(i)==i+1?i:p);
    if(p==s){
      cout<<-1<<endl;
      return 0;
    }
    a.push_back(p+1);
    for(int i=p;i+1<s;i++)
      b.at(i)=b.at(i+1);
  }
  for(int i=n-1;i>=0;i--)
    cout<<a.at(i)<<endl;
}