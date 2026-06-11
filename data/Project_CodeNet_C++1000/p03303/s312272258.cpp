#include <bits/stdc++.h>
using namespace std;

string s;
int N,w,i;
int main(){
  cin>>s>>w; N = s.size();
  for(i=0;i<N;i+=w){printf("%c",s[i]);}
}