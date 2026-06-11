#include<bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin >> N;

   for(int i=0;i<100;i++){
    for(int j=0;j<100;j++){
      if((N-4*i-7*j)==0) {cout <<"Yes"<<endl; return 0;}
    }
  }
   cout<<"No"<<endl;

return 0;
}
