
#include <iostream>
#include <string>
using namespace std;
int main(){
  int N;
  float x[10],sum=0.0;
  string u[10];
  cin >> N ;
  for (int i=0;i<N;i++){
    cin >> x[i];
    cin >> u[i];
  }
  for (int i=0;i<N;i++){
    if (u[i] == "JPY"){
      sum += float(x[i]);
    }else{
      sum += 380000.0*x[i];
    }
  }
  cout << sum <<endl;
}
