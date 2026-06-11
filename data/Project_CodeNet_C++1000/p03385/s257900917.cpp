#include <bits/stdc++.h>
using namespace std;
const int64_t INF=9999999999999999;

int main() {
   string S;
   cin>>S;
   set<char>t;
   t.insert(S[0]);
   t.insert(S[1]);
   t.insert(S[2]);
   if(t.size()==3){cout<<"Yes"<<endl;}
   else{cout<<"No"<<endl;}
return 0;}