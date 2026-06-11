#include<iostream>
#include<string>
using namespace std;
int main()
{
  int n,m,i,j;
  string s,t;
  cin >> s >> t;
  n=s.size();
  m=t.size();
  for(i=n-m;i>=0;i--){
    for(j=0;j<m;j++)
      if(t[j]!=s[i+j] && s[i+j]!='?')
        break;
    if(j==m)
      break;
  }
  if(i<0){
    cout << "UNRESTORABLE" << endl;
  }else{
    for(j=0;j<n;j++){
      if(s[j]!='?')
        cout << s[j];
      else if(j<i || j>=i+m)
        cout << 'a';
      else
        cout << t[j-i];
    }
    cout << endl;
  }
  return 0;
}