#include<bits/stdc++.h>
using namespace std;
int main(){
  int a,b;
  cin >> a >> b;
  cout << a-b+1;
  /*
  if(strlen(a)==3)cout << a[2] << a[1] << a[0];
  else cout << a;
  /*
  int n;
  cin >> n;
  int a[n],r[n],b[n],p=0,q=0;
  char s[n];
  for(int i=0;i<n;i++){
    r[i]=99999999;
    b[i]=99999999;
  }
  for(int i=0;i<n;i++){
    cin >> a[i] >> s[i];
    if(s[i]=='R'){
      r[p]=a[i];
      p++;
    }
    else{
      b[q]=a[i];
      q++;
    }
  }
  sort(r,r+n);
  sort(b,b+n);
  for(int i=0;i<n;i++){
    if(r[i]==99999999)break;
    cout << r[i] << endl;
  }
  for(int i=0;i<n;i++){
    if(b[i]==99999999)break;
    cout << b[i] << endl;
  }
  */
}
