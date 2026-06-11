#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int s[4];
    cin>>s[0];
    cin>>s[1];
    cin>>s[2];
    cin>>s[3];
    cout << fmin(s[0],s[1]) + fmin(s[2],s[3]);
  
}
