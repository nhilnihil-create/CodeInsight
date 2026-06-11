#include<iostream>
using namespace std;

int main(){
  int n,max=0;
  int a[101];
  cin >> n;
  for(int i=0;i<n;i++){
    cin >> a[i];
  }
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      if(max<a[i]-a[j]){max=a[i]-a[j];}
    }
  }
  cout << max;
}