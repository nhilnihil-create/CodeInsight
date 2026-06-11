#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N;
  string result = "Three";
  cin >> N;
  
  for (int i=0; i<N; i++){
    string a;
    cin >>a;
    
    if (a== "Y")
      result = "Four";
  }
  cout << result << endl;
  
}
