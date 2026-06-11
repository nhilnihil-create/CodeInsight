#include <bits/stdc++.h>
using namespace std;

int main() {
  int n,white=0;
  cin>>n;
  char a[n];
  for(int i=0;i<n;i++){
    char c;
    cin>>c;
    a[i]=c;
    if(c=='.')white++;
  }
  int b[n+1];
  b[0]=white;
  for(int i=0;i<n;i++){
    if(a[i]=='.')b[i+1]=b[i]-1;
    else b[i+1]=b[i]+1;
  }
  sort(b,b+n+1);
  cout<<b[0]<<endl;
}
