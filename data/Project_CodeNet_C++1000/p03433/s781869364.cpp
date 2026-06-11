#include <bits/stdc++.h>
using namespace std;
int main (){
   int N;
 int A;
   cin >> N;
 cin >> A;
  int x=N/500;
  N = N-500*x;
  if (A>=N){
  cout<<"Yes"<<endl;
  }else{
    cout<<"No"<<endl;
  }
}