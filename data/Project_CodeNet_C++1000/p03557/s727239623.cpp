#include <bits/stdc++.h>

using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define ll long long int

int main(){
int n;
cin>>n;
vector<ll> a,b,c;
rep(i,n){
  ll s;
  cin>>s;
  a.push_back(s);
}
rep(i,n){
  ll s;
  cin>>s;
  b.push_back(s);
}
rep(i,n){
  ll s;
  cin>>s;
  c.push_back(s);
}
sort(a.begin(),a.end());
sort(b.begin(),b.end());
sort(c.begin(),c.end());

ll ans=0;
rep(i,n){
  auto itr=lower_bound(a.begin(),a.end(),b[i]);
  auto itr2=upper_bound(c.begin(),c.end(),b[i]);
  auto count1=itr-a.begin(),count2=c.end()-itr2;
  ans+=count1*count2;
//cout<<"ans=="<<ans<<" "<<"count1=="<<count1<<" "<<"count2=="<<count2<<endl;
}

cout<<ans<<endl;

  return 0;
}
