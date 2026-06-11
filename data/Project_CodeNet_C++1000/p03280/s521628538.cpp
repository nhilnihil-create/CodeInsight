#include <iostream>
using namespace std;

int main()
{
  int width, length, road, area;
  road = 0;
  area = 0;

  cin >> width >> length;
  road = width + length - 1;
  area = width * length - road;

  cout << area << endl;
}
