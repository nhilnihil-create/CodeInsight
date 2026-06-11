#include<iostream>
using namespace std;

int main(){
  int n, v[50], c[50], sum = 0;
  cin >> n;
  for(int i = 0;i < n;i++){
    cin >> v[i];
  }
  for(int j = 0;j < n;j++){
    cin >> c[j];
  }
  for(int i = 0;i < n;i++){
    for(int j = 0;j < n;j++){
      if(i == j){
      if(v[i] > c[j]){
        sum += (v[i] - c[i]);
      }
     }
    }
  }
    cout << sum;
  }