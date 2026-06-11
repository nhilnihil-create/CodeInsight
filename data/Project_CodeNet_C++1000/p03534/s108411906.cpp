#include<bits/stdc++.h>
using namespace std;
main()
{
  string str;
  cin >> str;
  int kind=0;
  bool f=false;
  map<char,int>a;
  
  for(int i=0;i<str.size();i++){
    if(a.count(str[i])==0){
      kind++;
      a[str[i]]=0;
    }
    a[str[i]]++;
  }

  if((kind==2&&str.size()==2)||str.size()==1)
    f=true;
  
  if(a['a']==a['b']&&a['b']==a['c'])
    f=true;
  if(a['a']-1==a['b']&&a['b']==a['c'])
    f=true;
  if(a['a']==a['b']-1&&a['a']==a['c'])
    f=true;
  if(a['a']==a['b']&&a['b']-1==a['c'])
    f=true;
  if(a['a']==a['b']&&a['b']==a['c']-1)
    f=true;
  if(a['a']==a['b']-1&&a['b']==a['c'])
    f=true;
  if(a['a']-1==a['b']&&a['a']==a['c'])
    f=true;
  
  if(f)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;

  return 0;
}