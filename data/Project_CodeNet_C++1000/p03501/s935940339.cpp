#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int n,a,b,na;
    cin >>n >>a >>b;
    na=n*a;
    cout << fmin(na,b);
}
