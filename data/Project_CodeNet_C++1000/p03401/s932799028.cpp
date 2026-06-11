#include <iostream>
using namespace std;
int main(){
  int s; cin >> s; int ar[s+1]; ar[0] = 0; int sum = 0;
  for (int i = 1; i < s+1; i++)
  {cin >> ar[i]; sum += abs(ar[i-1]-ar[i]);}
  for (int i = 1; i < s; i++){
  cout << (sum - abs(ar[i-1]-ar[i])-abs(ar[i+1]-ar[i]))+abs(ar[i+1]-ar[i-1])+abs(ar[s]) << "\n";
  }
  cout << sum - abs(ar[s]-ar[s-1]) + abs(ar[s-1]) << endl;
  return 0; }