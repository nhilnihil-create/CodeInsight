#include <bits/stdc++.h>
using namespace std;

int main(){
  int n; cin>>n;
  vector<int> a(n);
  vector<int> b(n);
  for (int i=0; i<n; i++) cin>>a[i];
  for (int i=0; i<n; i++) cin>>b[i];
  
  long long minus=0;
  vector<int> plus(0);
  int ans=0;  
  for (int i=0; i<n; i++){
    if (b[i]>a[i]){
      minus+=b[i]-a[i];
      ans+=1;
    }
    else plus.push_back(a[i]-b[i]);
  }
  
  if (minus==0){
    cout<<0<<endl;
    return 0;
  }
  
  sort(plus.begin(),plus.end());
  reverse(plus.begin(),plus.end());
  for (auto d : plus){
    ans+=1;
    minus-=d;
    if (minus<=0){
      cout<<ans<<endl;
      return 0;
    }
  }
  cout<<-1<<endl;
}