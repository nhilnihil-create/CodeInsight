#include <bits/stdc++.h>
using namespace std;

int main() {   
 int N,A;
 cin>>N>>A;
  
  if(A>498){
    cout<<"Yes"<<endl;
  }
  else if(A%500>=N%500){
    cout<<"Yes"<<endl;
  }
  else {
    cout<<"No"<<endl;
  }
}
