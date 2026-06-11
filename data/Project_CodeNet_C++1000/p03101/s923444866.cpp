#include <iostream>

using namespace std;

int main()
{
    int row1, row2;
    int columns1, columns2;
    cin >> row1;
    cin >> columns1;
    cin >> row2;
    cin >> columns2;

    cout << (row1 - row2)*(columns1 - columns2) << endl;
    return 0;
}
