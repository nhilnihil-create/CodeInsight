#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin >> n;
  char s[n+1];
  cin >> s;
  int a[n],d[n];
  if(s[0]=='W')a[0]=1;
  else a[0]=0;
  for(int i=1;i<n;i++){
    a[i]=a[i-1];
    if(s[i]=='W')a[i]++;
  }
  if(s[n-1]=='E')d[n-1]=1;
  else d[n-1]=0;
  for(int i=n-2;i>-1;i--){
    d[i]=d[i+1];
    if(s[i]=='E')d[i]++;
  }
  int p=400000;
  for(int i=0;i<n;i++){
    if(i==0&&p>d[1])p=d[1];
    else if(i==n-1&&p>a[n-2])p=a[n-2];
    else{
      if(p>a[i-1]+d[i+1])p=a[i-1]+d[i+1];
    }
  }
  cout << p << endl;
}
