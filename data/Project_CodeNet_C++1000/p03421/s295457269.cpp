#include<iostream>
using namespace std;
#define df 0

int main(){
  if(df) printf("*debug mode*\n");
  int n,a,b; cin >> n >> a >> b;
  if(n>(long int)a*b || n<a+b-1){
    cout << "-1\n";
    return 0;
  }
  if(a==1){
    for(int i=n;i>0;i--){
      cout << i << (i!=1? " ":"\n");
    }
    return 0;
  }
  int q=(n-b)/(a-1), r=(n-b)%(a-1);
  for(int i=b;i>0;i--){
    cout << i << " ";
  }
  int i,j0=b;
  for(i=1;i<=r;i++){
    j0+=q+1;
    for(int j=0;j<q+1;j++){
      cout << j0-j << " ";
    }
  }
  for(;i<a;i++){
    j0+=q;
    for(int j=0;j<q;j++){
      cout << j0-j << " ";
    }
  }
  cout << "\n";
}

/// confirm df==0 ///
