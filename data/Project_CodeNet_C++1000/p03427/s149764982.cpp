#include <bits/stdc++.h>
using namespace std;
const int INF=999999999;

int main() {
 string N;
 cin>>N;
 bool k=false;
 for(int i=1;i<N.size();i++){
     if(N[i]!='9'){k=true;break;}
 }
 if(k){cout<<N[0]-'1'+9*(N.size()-1)<<endl;}
 else{cout<<9*(N.size()-1)+N[0]-'1'+1<<endl;}
 
 return 0;}