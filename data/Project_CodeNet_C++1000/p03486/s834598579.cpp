#include <bits/stdc++.h>
#define PI 3.1415926535897932
#define _GLIBCXX_DEBUG
using namespace std;
int main() {
  
  string S,T;
  cin>>S>>T;
  
  vector<char> x(S.size());
  for(int i=0;i<S.size();i++){
    x[i]=S[i];
  }
  sort(x.begin(),x.end());
  
  vector<char> y(T.size());
  for(int j=0;j<T.size();j++){
    y[j]=T[j];
  }
  sort(y.begin(),y.end());
  reverse(y.begin(),y.end());
  
  if(x<y){
    cout<<"Yes"<<endl;
  }
  else{
    cout<<"No"<<endl;
  }
}
