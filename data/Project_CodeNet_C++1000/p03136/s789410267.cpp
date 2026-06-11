#include<iostream>
#include<vector>
using namespace std;

int main() {
  int max = 0, sum=0;
  int n;
  cin >> n;
  vector <int> vec(n);
  cin >> vec[0];
  sum = max = vec[0];
  for(int i=1; i < n; i++)
  {
    cin >> vec[i];
    sum = sum + vec[i];
    if(max < vec[i])
      max = vec[i];
  }
  if(sum - max*2 > 0)
    cout << "Yes";
  else 
    cout <<"No";
  return 0;

}