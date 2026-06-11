#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N;
  cin >> N;
  vector<char> color(N);
  for(int i = 0;i < N;i++){
    cin >> color[i];
  }
  
  int count = 0;
  for(int i = 0;i < N;i++){
    if(color[i] == 'Y'){
      count++;
    }
  }
  if(count == 0)
    cout << "Three" << endl;
  else
    cout << "Four" << endl;
}