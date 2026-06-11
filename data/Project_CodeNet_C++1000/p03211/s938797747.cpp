#include <bits/stdc++.h>
using namespace std;
int main() {
string s;
cin >> s;
int fav = 753;
int min =1000;
for (int i = 0; i < s.size()-2; i++)
{
  int x = stoi(s.substr(i, 3));
  if(abs(x-fav)<min) min =abs(x-fav);
}
cout << min << endl;
    return 0;
}