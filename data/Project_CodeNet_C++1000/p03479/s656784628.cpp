#include<bits/stdc++.h>
using namespace std;
int main (){
  int64_t  X, Y;
  cin >> X >> Y;
  int64_t gap = Y - X + 1LL ;

  int64_t count = 0LL;
  int64_t p = X ;
  while(p < Y+1){
    count++;
    p = p * 2LL ;
    }
    
  cout << count << endl;
}