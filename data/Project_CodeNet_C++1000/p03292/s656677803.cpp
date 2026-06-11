#include<iostream>
using namespace std;

int main(){
  int A1, A2, A3;
  cin >> A1 >> A2 >> A3;
  int A12 = (A1-A2<0 ? -(A1-A2) : A1-A2);
  int A23 = (A2-A3<0 ? -(A2-A3) : A2-A3);
  int A31 = (A3-A1<0 ? -(A3-A1) : A3-A1);
  int min = 300;
  int costs[3] = {A12, A23, A31};
  for(int i=0; i<3; i++){
    for(int j=0; j<3; j++){
      if(i!=j) {
        min = (costs[i]+costs[j] < min ? costs[i]+costs[j] : min);
      }
    }
  }
  
  cout << min << endl;
  
  return 0;
}