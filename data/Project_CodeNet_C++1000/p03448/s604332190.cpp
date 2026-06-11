#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int A,B,C,XX;
  int syu=0;
  cin >> A >> B >> C >> XX;
  for (int X=0;X<=A*500;X+=500){
    for (int Y=0;Y<=B*100;Y+=100){
      for (int Z=0;Z<=C*50;Z+=50){
        if (X+Y+Z==XX){
          syu++;
        }
      }
    }
  }
  cout << syu << endl;
}
