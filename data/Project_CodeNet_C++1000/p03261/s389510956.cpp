#include <bits/stdc++.h>
using namespace std;
const int INF=999999999;
int main() {
 int N;
 cin>>N;
 vector<string>W(N);
 set<string>a;
 for(int i=0;i<N;i++){
     cin>>W[i];
 }
  a.insert(W[0]);
 for(int i=1;i<N;i++){
     if(W[i-1].at(W[i-1].size()-1)!=W[i].at(0)||a.count(W[i])){
      cout<<"No"<<endl;return 0;
     }
     a.insert(W[i]);
 }
 cout<<"Yes"<<endl;   
 return 0;}