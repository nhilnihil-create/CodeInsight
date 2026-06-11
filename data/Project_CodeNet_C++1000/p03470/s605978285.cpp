#include<bits/stdc++.h>
using namespace std;
 
int main() {
  long long N,i;
  cin>>N;
  long long ans=0;
 
  long long a[N];
  for (i=0;i<N;i++)cin>>a[i];

  long long b[110]={0};
  for (i=0;i<N;i++)b[a[i]]++;
  
  for (i=0;i<110;i++){
    if(b[i])ans++;
  }
  //sort(a,a+N);
  //reverse(a,a+N);
  
  cout << ans << endl;
}