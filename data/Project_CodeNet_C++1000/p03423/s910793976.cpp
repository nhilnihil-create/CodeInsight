#include <bits/stdc++.h>
using namespace std;

int main() {
int N;
  cin>>N;
  if(N%3==0){
    cout<<N/3<<endl;
  }
 else if(N%3==1){
   cout<<(N-4)/3+1<<endl;
 }
  else if(N%3==2){
    cout<<(N-5)/3+1<<endl;
  }
}