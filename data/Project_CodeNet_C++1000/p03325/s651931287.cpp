#include<bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin >> N;
  long long count=0;
  for(int i=0;i<N;i++){
    int A;
    cin >> A;
    while(A%2==0){
      count++;
      A/=2;
    }
  }
  cout << count << endl;
}