#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
  int N;
  vector<int> a;
  cin >> N;
  for(int i = 0; i < N; ++i)
  {
    int n;
    cin >> n;
    a.push_back(n);
  }
  
  sort(a.begin(), a.end(), greater<int>());
  
  int score = 0;
  for(int i = 0; i < N; ++i)
  {
    score += i%2==0 ? a[i] : a[i] * (-1);
  }
  
  cout << score << endl;
}