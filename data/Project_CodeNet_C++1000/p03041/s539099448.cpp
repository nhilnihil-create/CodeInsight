#include <bits/stdc++.h>
using namespace std;
using P=pair<int,int>;
int main(){
int N,K;
  string S;
cin>>N>>K;
  cin>>S;
 if(S.at(K-1)=='A'){
 S.at(K-1)='a';
 }
   else if(S.at(K-1)=='B'){
 S.at(K-1)='b';
 }
   if(S.at(K-1)=='C'){
 S.at(K-1)='c';
 }
  cout<<S;
}
  