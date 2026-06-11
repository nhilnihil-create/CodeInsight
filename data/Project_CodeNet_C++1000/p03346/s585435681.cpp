#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,p[200010];
  cin >> n;
  int i;
  vector<int> x(200010);
  for(i=0;i<n;i++){
    cin >> p[i];
    x[p[i]]=i+1;
  }
  int ans=0,count=0,now=0;
  for(i=1;i<=n;i++){
    if(x[i]>now){
      count++;
      now=x[i];
    }
    else{
      ans=max(ans,count);
      now=x[i],count=1;
    }
  }
  ans=max(ans,count);
  cout << n-ans << endl;
}