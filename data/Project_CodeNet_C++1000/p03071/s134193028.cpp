#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int A , B , s , m ;
    cin >> A >> B ;
    s = fmax (A , B);
    m = fmin ( A , B);
    if((s-1) >= m)
    {
        cout << 2 * s - 1  << endl;
    }
    else
    {
        cout << s + m << endl;
    }

    return 0;
}
