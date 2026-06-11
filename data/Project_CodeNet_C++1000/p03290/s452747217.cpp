#include <bits/stdc++.h>
using namespace std;

int main() {
  int D, G;
  cin >> D >> G;
  G /= 100;

  vector<int> p(D), c(D);
  vector<int> CompletePoint(D);
  int NumLeast=0;
  for (int i = 0; i < D; i++) {
    cin >> p.at(i) >> c.at(i);
    CompletePoint.at(i) = (p.at(i)*(i+1)+c.at(i)/100);
    NumLeast += p.at(i);
  }
  
  for(int i = 0; i < (1 << (D)); i++){
    bitset<10> tmp(i);
    int Point=0;
    int Num=0;
    int id=0;
    for(int j = 0; j < (D); j++) {
      if(tmp.test(j)) {
        Point += CompletePoint.at(j);
        Num += p.at(j);
      } else {
        id = j;
      }
    }

    if (G - Point <= 0) {
      if (NumLeast > Num) {
        NumLeast = Num;
      }
    } else if (G - Point <= (id+1)*(p.at(id)-1)) {
      if ((G - Point)%(id+1)==0) {
        Num+=(G - Point)/(id+1);
      } else {
        Num+=((G - Point)/(id+1)+1);
      }
      if (NumLeast > Num) {
        NumLeast = Num;
      }
    }
  }
  cout << NumLeast;
}