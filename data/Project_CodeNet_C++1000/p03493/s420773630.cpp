#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    string s;
    cin >> s;
  	int i;
    int counter = 0;
    if (s[0] == '1') ++counter;
    if (s[1] == '1') ++counter;
    if (s[2] == '1') ++counter;
    cout << counter << endl;
}