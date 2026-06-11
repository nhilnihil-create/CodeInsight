#include <bits/stdc++.h>
using namespace std;

int main() {
int N;
  cin >> N;
  int N10=N/10;
   int N000=N%1000;
  if(N10%111==0){
    cout << "Yes" << endl;
  }
  else if(N000%111==0){
    cout << "Yes" <<endl;
  }
    else{
      cout <<"No" <<endl;
    }
}
