#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    unsigned A, B, X;
    cin >> A >> B >> X;

    if( A <= X)
    {
        if(A + B-1 >= X)
        {
            cout << "YES" << endl;
        } else
        {
            cout << "NO" << endl;
        }
    } else
    {
        cout << "NO" << endl;
    }
    
    return 0;
}
