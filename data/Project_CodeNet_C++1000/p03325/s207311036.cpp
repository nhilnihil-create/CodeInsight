#include <bits/stdc++.h>
using namespace std;

int main(){
  int n; cin>>n;
  vector<int> a(n);
  for (int i=0; i<n; i++) cin>>a[i];
  
  int ans=0;
  for (auto d : a){
    int t_ans=0;
    while (d%2==0){
      d/=2;
      t_ans+=1;
    }
    ans+=t_ans;
  }
  cout<<ans<<endl;
}