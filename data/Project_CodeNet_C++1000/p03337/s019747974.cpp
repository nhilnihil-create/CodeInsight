#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int A , B ;
    cin >> A >> B ;
    A = fmax((A * B) , fmax((A-B) , (A + B)));

    cout << A << endl;
    return 0;
}
