#include <bits/stdc++.h>
using namespace std;

int main()
{
  int N,T,A;
  cin >> N >> T >> A;
  
  vector<int> h(N);
  for(int i = 0; i < N; i++){
    cin >> h.at(i);
  }
  
  double maxhei = 999999;
  int place = 0;
  for(int i = 0; i < N; i++){
    double hei = A - (T - (h.at(i) * 0.006));
    if(hei > 0){
      if(hei < maxhei){
        maxhei = hei;
        place = i;
      }
    }else{
      hei = -hei;
      if(hei < maxhei){
        maxhei = hei;
        place = i;
      }
    }
  }
  
  cout << place+1 << endl;
  
}