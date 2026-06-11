#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  
  string str;
  str = to_string(N);
  
  int count;
  
  for (int i = 0; i < str.size(); i++)
    count += (int)str[i] - 48;
  
  if (N % count == 0)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
}
    
  