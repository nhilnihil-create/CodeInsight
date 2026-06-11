#include<bits/stdc++.h>
using namespace std;
bool f(int x){
  int i;
  if(x%2==0&&x/2>1) return false;
  for(i=3;i*i<=x;i+=2) if(x%i==0&&x/i>1) return false;
  return true;
}
int main(){
  int q,l,r,i;
  vector<int> v;
  for(i=3;i<1e5;i+=2) if(f(i)&&f((i+1)/2)) v.push_back(i);
  cin>>q;
  for(i=0;i<q;i++){
    cin>>l>>r;
    cout<<distance(lower_bound(v.begin(),v.end(),l),upper_bound(v.begin(),v.end(),r))<<endl;
  }
}