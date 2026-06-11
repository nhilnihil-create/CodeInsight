#include<bits/stdc++.h>
using namespace std;

int main(){
  int N,tmp;
  cin >>N;
  string s;
  cin >> s;
  vector<int>a(N,0);
  for(int i=1;i<N;i++){
    if(s.at(i)=='E')
      a.at(0)++;
  }
  tmp=a.at(0);
  for(int i=1;i<N;i++){
    a.at(i)=a.at(i-1);
    if(s.at(i)=='E')
    a.at(i)=a.at(i-1)-1;
    if(s.at(i-1)=='W')
      a.at(i)=a.at(i)+1;
    tmp=min(tmp,a.at(i));
  }
    cout <<tmp<<endl; 
}