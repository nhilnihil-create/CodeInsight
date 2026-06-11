#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin>>N;
  for (int i=0; i<10; i++){
    if (111*i<N&&N<=111*(i+1)){
      cout<<111*(i+1)<<endl;
    }
  }
}