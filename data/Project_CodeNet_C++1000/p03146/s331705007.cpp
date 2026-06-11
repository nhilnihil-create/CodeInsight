#include <iostream>
#include <unordered_set>
using namespace std;
int main()
{
  long long s;
  cin >> s;
  unordered_set<long long> U;
  U.insert(s);
  int m = 1;
  while(true) {
    if(s%2==0) s = s/2;
    else s = 3*s + 1;
    if(U.find(s)!=U.end()) break;
    U.insert(s);
    m++;
  }
  cout << m+1 << endl;
}