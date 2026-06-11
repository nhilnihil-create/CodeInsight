#include<bits/stdc++.h>
using namespace std;

int main(){
  int64_t n,h;
  cin >> n >> h;
  vector<int64_t>a(n);
  vector<int64_t>b(n);
  for(int i=0;i<n;i++)
    cin >> a.at(i) >> b.at(i);
  sort(a.begin(),a.end(),greater());
  sort(b.begin(),b.end(),greater());
  bool ok=false;
  int64_t sum=0,ans=0,s=0;
  while(s<n&&b.at(s)>a.at(0)&&sum<h){
    sum+=b.at(s);
    s++;
  }
  ans=s;
  ok=(sum>=h);
  if(!ok){
    h-=sum;
    ans+=h/a.at(0)+(h%a.at(0)!=0);
  }
  cout << ans << endl;
  return 0;
}
  