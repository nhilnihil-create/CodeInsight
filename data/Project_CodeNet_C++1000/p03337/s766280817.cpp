#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);

    int A, B;
    cin >> A >> B;

    int largest = A + B;

    if(A - B > largest) largest = A - B;
    if(A * B > largest) largest = A * B;

    cout << largest << endl;

    return 0;
}
