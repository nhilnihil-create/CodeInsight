#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N;
  cin >> N;
  vector<int> D(N);
  int count= 1;
  
  for (int i = 0; i < N; i++)
    cin >> D.at(i);
  
  sort(D.begin(), D.end());
  
  for (int i = 0; i < N-1; i++){
   if(D.at(i) < D.at(i+1) )
     count++;
  }
  

  cout << count << endl;
}