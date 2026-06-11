#include <bits/stdc++.h>
using namespace std;

int main()
{
 int input, hundred, ten, one;
 cin >> input;
 hundred = input / 100;
 ten = (input % 100) / 10;
 one = (input % 10) / 1;
 cout << hundred + ten + one << endl;
}