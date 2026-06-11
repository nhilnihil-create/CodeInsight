#include <iostream>
#include <cmath>
#include <sstream>
using namespace std;
int main()
{
    int a,b,c,d,ab,cd;
    cin >>a>>b>>c>>d;
    ab=a+b;
    cd=c+d;
    if (cd==ab)
    cout << "Balanced";
    if (cd>ab)
    cout << "Right";
    if (cd<ab)
    cout << "Left";

}
