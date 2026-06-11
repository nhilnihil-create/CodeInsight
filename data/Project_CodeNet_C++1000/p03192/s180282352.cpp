#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin >> N;
  int count=0;
  if(N%10==2){
    count++;
  }
  if(N/1000==2){
    count++;
  }
  if(N%1000-N%100==200){
    count++;
  }
  if(N%100-N%10==20){
    count++;
  }
  cout << count << endl;
}
