#include<bits/stdc++.h>
using namespace std;


int main(){
  int n;
  cin >> n;
  vector<int> a(n),b(n);
  for(int i=0;i<n;++i){
    cin >> a[i];
  }
  for(int i=0;i<n;++i){
    cin >> b[i];
  }
  bool ok = true;
  for(int i=0;i<n;++i){
    if(a[i]<b[i]) ok=false;
  }
  if(ok){
    cout << '0' << endl;
    return 0;
  }
  int kazu=0;
  long long s=0;
  priority_queue<long long> que;
  for(int i=0;i<n;++i){
    if(a[i]<b[i]){
      kazu++;
      s+=(b[i]-a[i]);
    }
    if(a[i]>=b[i]){
      que.push(a[i]-b[i]);
    }
  }
  int num=0;
  while(!que.empty() && s>0){
    num++;
    s=s-que.top();
    que.pop();
  }
  if(s>0){
    cout << "-1" << endl;
  }else{
    int ans=num+kazu;
    cout << ans << endl;
  }
  return 0;

}
