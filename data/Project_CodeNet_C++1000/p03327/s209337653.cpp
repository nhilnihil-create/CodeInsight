#include <iostream>

using namespace std;

int main()
{
    int N;
    cin >> N;

    if (N <= 999) {cout << "ABC";}
    else if ((N >= 1000) && (N <=1998)) {cout << "ABD";}

    return 0;
}
