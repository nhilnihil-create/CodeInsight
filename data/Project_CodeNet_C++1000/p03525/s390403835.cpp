#include <iostream>
#include <algorithm>
using namespace std;

string bit(int n,int d){
  string ans="";
  for(int i=0;i<d;i++){
    char c='0'+n%2;
    n/=2;
    ans=c+ans;
  }
  return ans;
}

int main(){
  int n;
  cin >> n;
  int a[n];
  for(int i=0;i<n;i++){
    cin >> a[i];
  }
  sort(a,a+n);
  if(n==1){
    cout << a[0] << endl;
    return 0;
  }
  for(int i=0;i<n-2;i++){
    if(a[i]==a[i+2]){
      cout << 0 << endl;
      return 0;
    }
  }
  if(n>12&&a[0]==0){
    cout << 0 << endl;
    return 0;
  }
  else if(n>12){
    cout << 1 << endl;
    return 0;
  }
  int ans=0;
  for(int i=0;i<1<<n;i++){
    string s=bit(i,n);
    int time[n+2];
    for(int j=0;j<n;j++){
      if(s[j]=='1') time[j]=24-a[j];
      else time[j]=a[j];
    }
    time[n]=0,time[n+1]=24;
    sort(time,time+n+2);
    int count=24;
    for(int j=0;j<n+1;j++){
      count=min(count,time[j+1]-time[j]);
    }
    ans=max(ans,count);
  }
  cout << ans << endl;
}
