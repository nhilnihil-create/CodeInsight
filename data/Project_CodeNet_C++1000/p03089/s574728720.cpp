#include <bits/stdc++.h>
using namespace std;
//解説AC
int main() {
  int n; cin >>n;
  vector<int>a(n),b(n);
  for(int i=0;i<n;i++)cin>>a[i];
  int count=0;
  int x=n;
  while(x>0){
    for(int i=x-1;i>=0;i--){
      //cout<<i<<" "<<a[i]<<endl;
      if(a[i]==i+1){
        b[count]=a[i];
        count++;
        a.erase(a.begin()+i);
        break;
      }
    }
    if(count==n)break;
    x--;
  }
  if(count!=n){
    cout<<-1<<endl;
    return 0;
  }
  for(int i=count-1;i>=0;i--){
    cout<<b[i]<<endl;
  }
  return 0;
}
