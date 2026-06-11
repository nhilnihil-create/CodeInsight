#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int main()
{
  int a,b;
  cin >> a;
  vector <string> red(a);
  for(int i=0;i<a;i++) cin >> red[i];
  cin >> b;
  vector <string> blue(b);
  for(int i=0;i<b;i++) cin >> blue[i];
  int sum = 0;
  string wa;
  for(int i=0;i<a;i++){
    int aka = 0;
    int ao = 0;
    wa = red[i];
    for(int j =0;j<a;j++){
      if(red[j]==wa)aka++;
    }
    for(int j =0;j<b;j++){
      if(blue[j]==wa)ao++;
    }
    sum = max(sum,aka-ao);
  }
  cout << sum << endl;
}