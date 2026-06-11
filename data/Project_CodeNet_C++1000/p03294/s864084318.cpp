#include<bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin >> N;
  int Ans=0;
  int k;
  for(int i=0; i<N; i++){
    cin >> k;
    Ans+=k-1;
  }
  cout << Ans << endl;
}