#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
  int n;
  cin>>n;
  if(n%2==0){
    cout<<(n-2)*n/2<<endl;
    for(int i=1;i<=n-1;i++){
      for(int j=i+1;j<=n;j++){
        if(i+j!=n+1){
          cout<<i<<" "<<j<<endl;
        }
      }
    }
    return 0;
  }
  int count=n-1;
  int vec[n];
  for(int i=1;i<n;i++){
    vec[i]=(n*(n-1)/2)-n;
  }
  for(int i=1;i<n-1;i++){
    for(int j=n-1;j>i;j--){
      if(i+j!=n){
        vec[i]-=j;
        count++;
      }
    }
  }
  cout<<count<<endl;
  for(int i=1;i<n;i++){
    cout<<i<<" "<<n<<endl;
  }
  for(int i=1;i<n-1;i++){
    for(int j=n-1;j>i;j--){
      if(i+j!=n){
        cout<<i<<" "<<j<<endl;
      }
    }
  }
  return 0;
}