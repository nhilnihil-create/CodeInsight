#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
  int n;
  cin >> n;
  vector<int> a(n);
  for(int i=0;i<n;i++) cin >> a[i];

  sort(a.begin(),a.end(),greater<int>());

  int suma = 0,sumb = 0;
  for(int i=0;i<n;i++){
    if(i%2 == 0) suma += a[i];
    else sumb += a[i];
  }

  cout << suma - sumb << endl;
}