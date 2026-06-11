#include <bits/stdc++.h>
using namespace std;

int main() {
  int n,ame;
  cin >>n>>ame;
  vector<int>a(n);
  long long sum=0;
  for(int i=0;i<n;i++){
    cin>>a[i];
  }
  sort(a.begin(),a.end());
  if(ame<a[0]){
    cout<<0<<endl;
    return 0;
  }
  int count =0;
  for(int i=0;i<n;i++){
    sum+=a[i];
    if(sum>ame)break;
    if(i==n-1){
      //cout<<sum<<" "<<ame<<endl;
      if(sum==ame){
        count++;
        break;
      }else break;
    }
    count++;
  }
  cout<<count<<endl;
  return 0;
}