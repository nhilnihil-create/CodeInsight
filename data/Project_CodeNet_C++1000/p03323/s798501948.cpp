#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    unsigned A, B;
    cin >> A >> B;

    if(A > 8 || B > 8)
    {
        cout << ":(" << endl;
    } else
    {
        cout << "Yay!" << endl;
    }
    
    return 0;
}
