#include<bits/stdc++.h>
using namespace std;
using ll=int64_t;
using vll=vector<ll>;
using vi=vector<int>;
int main(){
  string s;
  cin>>s;
  int n=s.length(),i,c=0;
  for(i=0;i<n;i++) if(i%2==0 && s.at(i)=='0' || i%2==1 && s.at(i)=='1') c++;
  cout<<min(c,n-c)<<endl;
}