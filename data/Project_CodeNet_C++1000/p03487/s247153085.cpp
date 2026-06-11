#include <bits/stdc++.h>
using namespace std;
int main(){
  int N; cin>>N;
  long long ans=0;
  vector<int>count(100001);
  for(int i=0;i<N;i++){
    int a;cin>>a;
    if(a>100000)ans++;
    else count[a]++;
  }
  for(int i=0;i<100001;i++){
    if(count[i]<i)ans+=count[i];
    else ans+=count[i]-i;
  }
  cout<<ans<<endl;
}