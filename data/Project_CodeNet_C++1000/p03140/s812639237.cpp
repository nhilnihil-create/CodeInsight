#include <bits/stdc++.h>

using namespace std;

int main(){
 int n;
  cin >> n;
 string a,b,c;
  cin >> a >> b >> c;
  
 long res=0;
  
  for(int i=0;i<n;i++){
   if(a[i]!=b[i]&&b[i]!=c[i]&&c[i]!=a[i]) res+=2;
   else if((a[i]==b[i]&&b[i]!=c[i])||(b[i]==c[i]&&c[i]!=a[i])||(c[i]==a[i]&&a[i]!=b[i])) res+=1;
  
  }
  
  
  cout << res << endl;
}