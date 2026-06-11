#include<iostream>
using namespace std;

int main(){

  int n, d, x, count=0;
  cin>>n;
  cin>>d>>x;
  int a[n];

  for(int i=0; i<n; i++) cin>>a[i];

  for(int i=0; i<n; i++){
    for(int j=0; j<d; j+=a[i]){
        count++;
    }
  }

  cout<<count+x<<endl;

  return 0;
}
