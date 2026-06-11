#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin>>n;
  vector<int> a(n);
  for(int i=0;i<n;i++)
    cin>>a.at(i);
  int l=0;
  int r=0;
  int64_t s=0;
  int o=0;
  while(1){
    if((o&a.at(r))==0){
      s+=r-l+1;
      o|=a.at(r);
      r++;
      if(r==n)
        break;
    }else{
      o^=a.at(l);
      l++;
    }
  }
  cout<<s<<endl;
}