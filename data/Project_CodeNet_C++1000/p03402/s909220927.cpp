#include <iostream>

using namespace std;

bool isBlack[100][100];

int main()
{
    for (int i = 0; i < 100; i++)
    {
        for (int j = 0; j < 100; j++)
        {
            isBlack[i][j] = (i < 50);
        }
    }

    int a, b;
    cin >> a >> b;
    a--;
    b--;

    for (int i = 0; i < a; i++)
    {
        int x = i / 50;
        int y = i % 50;
        isBlack[2 * x][2 * y] = false;
    }

    for (int i = 0; i < b; i++)
    {
        int x = i / 50;
        int y = i % 50;
        isBlack[2 * x + 51][2 * y] = true;
    }

    cout << 100 << " " << 100 << endl;
    for (int i = 0; i < 100; i++)
    {
        for (int j = 0; j < 100; j++)
        {
            cout << (isBlack[i][j] ? '#' : '.');
        }
        cout << endl;
    }
    return 0;
}