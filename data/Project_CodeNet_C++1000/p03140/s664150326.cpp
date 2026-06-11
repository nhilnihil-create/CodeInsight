#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int n;
  cin>>n;
  string a,b,c;
  cin >>a>>b>>c;
  int count=0;
  for(int i=0;i<n;i++){
    int kazu=0;
    if(a[i]==b[i]&&a[i]==c[i]){
    }else if(a[i]!=b[i]&&a[i]==c[i]){
      count++;
    }else if(a[i]!=b[i]&&a[i]!=c[i]){
      if(b[i]==c[i]){
        count++;
      }else{
        count+=2;
      }
    }else if(a[i]==b[i]&&a[i]!=c[i]){
      count++;
    }
  }
  cout<<count<<endl;
  return 0;
}