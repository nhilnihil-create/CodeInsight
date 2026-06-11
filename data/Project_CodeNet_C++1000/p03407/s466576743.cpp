#include <iostream>

using namespace std;

int main()
{
    int A , B , C , D;
    cin >> A >> B >> C;
    D = C - (A + B);
    if (D > 0) {cout << "No";}
    else {cout << "Yes";}
}