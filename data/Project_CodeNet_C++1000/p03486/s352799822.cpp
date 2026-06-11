#include<bits/stdc++.h>
using namespace std;

int main(){
  string a,b;
  cin >> a >> b;
  vector<char>ast(a.size());
  vector<char>bst(b.size());
  for(int i=0;i<a.size();i++)
    ast.at(i)=a.at(i);
  for(int i=0;i<b.size();i++)
    bst.at(i)=b.at(i);
  sort(ast.begin(),ast.end());
  sort(bst.begin(),bst.end(),greater());
  bool ans=false,br=false;
  for(int i=0;i<min(ast.size(),bst.size());i++){
    if(ast.at(i)!=bst.at(i)){
      if(ast.at(i)<bst.at(i))
        ans=true;
      else
        ans=false;
      br=true;
      break;
    }
  }
  if(!br)
    ans=a.size()<b.size();
  cout << (ans?"Yes":"No") << endl;
}