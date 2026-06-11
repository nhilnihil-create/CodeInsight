#include <iostream>
#include <cmath>
using namespace std;

int main()
{
 int apple, piece, pie, total;
 pie = 0;
 total = 0;

 cin >> apple >> piece;
 apple *= 3;
 total = apple + piece;

 pie = total / 2;

 cout << pie << endl;
}