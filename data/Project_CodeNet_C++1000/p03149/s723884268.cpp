#include <bits/stdc++.h>
using namespace std;

class Main{
  private:
  	
  public:
int n;
};
int main()
{
  //cout << n <<endl;
  vector<int> list(4);
  for(int i =0 ; i < 4; i++){
    cin >> list.at(i);
  }
  bool b;
  b = (count(list.begin(), list.end(), 1) == 1 && count(list.begin(), list.end(), 7) == 1
       && count(list.begin(), list.end(), 9) == 1 && count(list.begin(), list.end(), 4) == 1);
  string s;
  s = b? "YES" : "NO";
  cout << s;
}