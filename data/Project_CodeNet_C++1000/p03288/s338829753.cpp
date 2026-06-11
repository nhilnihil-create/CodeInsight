#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
 
int main(){
  int a;
  cin >> a;
  if(a<1200){
    cout << "ABC" << endl;
  }
  else if(a<2800){
    cout << "ARC" << endl;
  }
  else{
    cout << "AGC" << endl;
  }
}