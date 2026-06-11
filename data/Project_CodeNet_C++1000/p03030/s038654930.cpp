#include <bits/stdc++.h>
using namespace std;
int main() {
  int N;
  cin>>N;
  vector<tuple<string,int,int>> vt(N);
  for(int i=0;i<N;i++){
    string s;
    int p;
    cin>>s>>p;
    vt[i]=make_tuple(s,-p,i+1);
  }
  sort(vt.begin(),vt.end());
  
  for(int i=0;i<N;i++)cout<<get<2>(vt[i])<<endl;
}