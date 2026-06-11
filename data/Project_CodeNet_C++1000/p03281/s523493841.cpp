#include <iostream>

using namespace std;

int main(void)
{
    int N;
    cin >> N;

    if (N < 105)
    {
        cout << 0 << endl;
    }
    else
    {
        int valNum = 0;
        for (int i = 105; i <= N; i += 2)
        {
            int num = 0;
            for (int j = 1; j <= N; j++)
            {
                if (i % j == 0)
                    num++;
            }
            if (num == 8)
            {
                valNum++;
            }
        }
        cout << valNum << endl;
    }

    return 0;
}