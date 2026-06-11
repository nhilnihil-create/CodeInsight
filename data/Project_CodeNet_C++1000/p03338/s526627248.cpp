#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  string s;
  cin>>n>>s;
  int m=0;
  for(int i=1;i<n;i++){
    set<char> f;
    set<char> b;
    for(int j=0;j<n;j++){
      if(j<i)
        f.insert(s.at(j));
      else
        b.insert(s.at(j));
    }
    int c=0;
    for(char x:f)
      for(char y:b)
        if(x==y)
          c++;
    m=max(m,c);
  }
  cout<<m<<endl;
}