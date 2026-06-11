#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin >>N;
  int a[N];
  int gu=0;
  for(int i=0;i<N;i++){
    cin >>a[i];
    if (a[i]%2==0){
      gu++;
    }
  }
  cout<<pow(3,N)-pow(2,gu)<<endl;
  return 0;
}

    