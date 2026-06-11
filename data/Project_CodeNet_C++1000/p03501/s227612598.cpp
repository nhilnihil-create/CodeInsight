#include <iostream>

using namespace std;

int main()
{
    int N , A , B ;
    cin >> N >> A >> B ;
    A = A * N ;
    if(A <= B)
    {
        cout << A  << endl;
    }
    else
    {
        cout << B << endl;
    }

    return 0;
}
