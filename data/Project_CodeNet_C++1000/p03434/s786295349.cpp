#include <bits/stdc++.h>
using namespace std;

 int main() {
   int N;
   int A=0;
   int B=0;
   cin>>N;
  vector<int> test(N);
  
  for(int i=0;i<N;i++){
   cin>>test.at(i);
   }
   sort(test.rbegin(),test.rend());
  
 for(int i=0;i<N;i=i+2){
   A=A+test.at(i);
 }
 for(int i=1;i<N;i=i+2){
   B=B+test.at(i);
 }
   cout<<A-B<<endl;
 }