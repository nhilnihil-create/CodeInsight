#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin>>n;
  vector<int>V(n);
  vector<int>C(n);
  int sum=0;
  for (int i=0; i<n; i++) cin>>V[i];
  for (int i=0; i<n; i++) cin>>C[i];
  for (int i=0; i<n; i++){
    if (V[i]>C[i]){
      sum += V[i]-C[i];
    }
  }
  cout<<sum;
}