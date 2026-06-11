#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;
const int inf = 1001001001;

int main(){
  int n;
  cin >> n;
  
  string title;
  string number;
  
  if(n <= 999){
    title = "ABC";
    number = to_string(n);
  }
  
  if(n > 999){
    title = "ABD";
    number = to_string(n-999);
  }
  cout << title << endl;
}