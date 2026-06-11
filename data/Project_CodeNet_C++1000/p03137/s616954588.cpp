#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int n,m;
  cin >>n>>m;
  if(n>=m){
    cout<<0<<endl;
    return 0;
  }
  vector<int>a(m);
  for(int i=0;i<m;i++)cin>>a[i];
  sort(a.begin(),a.end());
  priority_queue<int>q;
  long long kotae=0;
  for(int i=0;i<m-1;i++){
    int x=abs(a[i+1]-a[i]);
    //cout<<x<<" ";
    q.push(x);
    kotae+=x;
  }
  for(int i=0;i<n-1;i++){
    int y=q.top();q.pop();
    kotae-=y;
  }
  cout<<kotae<<endl;
  return 0;
}