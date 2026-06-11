#include<bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  vector<int64_t>a(n);
  vector<int64_t>b(n);
  for(int i=0;i<n;i++)
    cin >> a.at(i);
  for(int i=0;i<n;i++)
    cin >> b.at(i);
  vector<int64_t>h(n);
  for(int i=0;i<n;i++)
    h.at(i)=b.at(i)-a.at(i);
  sort(h.begin(),h.end(),greater());
  int64_t ans=0,m=0;
  for(int i=0;i<n;i++){
    if(h.at(i)>0){
      m+=h.at(i);
      ans++;
    }else{
      break;
    }
  }
  for(int i=h.size()-1;i>=0;i--){
    if(m<=0)
      break;
    m+=h.at(i);
    ans++;
  }
  if(m>0)
    cout << -1 << endl;
  else 
    cout << ans << endl;
  return 0;
}