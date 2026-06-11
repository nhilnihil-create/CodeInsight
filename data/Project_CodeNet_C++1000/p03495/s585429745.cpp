#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
 
int main(){
  int n, k;
  cin >> n >> k;
  int a[n]={}, cnt=0;
  for(int i=0; i<n; i++){
    int b;
    cin >> b;
    b--;
    if(a[b]==0) cnt+=1;
    a[b]++;
  }
  priority_queue<int,  vector<int>, greater<int>> que;
  for(int i=0; i<n; i++){
    if(a[i]!=0) que.push(a[i]);
  }
  int ans = 0;
  while(cnt>k){
    ans += que.top();
    que.pop();
    cnt--;
  }
  cout << ans << endl;
  return 0;
}
