#include<bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin >> N;
  int num[N];
  int count = -1;
  bool flag =true;
  
  for(int i=0; i<N; i++){
    cin >> num[i];
  }
  
  while(flag){
    for(int i=0; i<N && flag; i++){
      if(num[i]%2 != 0)flag = false;
      num[i] /= 2;
    }
    count++;
  }
  cout << count << endl;
  return 0;
   
}