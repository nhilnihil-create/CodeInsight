#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N;
  cin >> N;
  
  bool p=false, w=false, g=false, y=false;
  for(int i=0; i<N; i++){
    string x;
    cin >> x;
    if(x == "P")
      p = true;
    if(x == "W")
      w = true;
    if(x == "G")
      g = true;
    if(x == "Y")
      y = true;
  }
  
  int num = 0;
  if(p)
    num++;
  if(w)
    num++;
  if(g)
    num++;
  if(y)
    num++;
  
  if(num == 3){
    cout << "Three" << endl;
  }
  if(num == 4){
    cout << "Four" << endl;
  }
}