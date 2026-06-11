#include <bits/stdc++.h>
using namespace std;

 int main() {
   int N;
   int A=0;
   int sum=0;
  cin>>N;
  vector<int> test(101);
  
  for(int i=0;i<N;i++){
    cin>>A;
    test.at(A)=1;
  }
    
  for(int i=0;i<101;i++){
    sum=sum+test.at(i);
  }
   cout<<sum<<endl;
 }