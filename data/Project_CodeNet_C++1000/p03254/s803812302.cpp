#include<bits/stdc++.h>
using namespace std;

int main (){
  int N,x;
  cin >> N >> x;
  
  vector<int> a(N);
  for (int i=0;i<N;i++){
    cin >> a[i];
  }
  
  sort(a.begin(),a.end());
  
  int sum=0;
  
  for(int i=0;i<N;i++){
    sum += a[i];
    if(sum > x){
      cout << i << endl;
      return 0;
    }
  }
  
  if(sum == x){
    cout << N << endl;
  }
  else{
    cout << N-1 << endl;
  }
  
}