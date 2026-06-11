#include<bits/stdc++.h>
using namespace std;

int main(){
  string S,T;cin>>S>>T;
  sort(S.begin(),S.end());
  sort(T.begin(),T.end());
  reverse(T.begin(),T.end());
  cout<<(S<T?"Yes":"No")<<endl;
}