#include <bits/stdc++.h>

using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define ll long long int

int main(){
  int n,k;
  cin>>n>>k;
  int a[n];
  rep(i,n)
    cin>>a[i];
  int hoge=k,count=1;;
  for(int i=0;;i++){ 
    if(hoge<n)
    count++;
    else  if(hoge>=n){
      cout<<count<<endl;
      return 0;
    }
    hoge+=k-1;
  }



  return 0;
}
