#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;

    for (int i = 0;i <= 25;i++)
    {
        for (int n = 0;n <= 14;n++)
        {
            if (N == 4 * i + 7 * n)
            {
                cout << "Yes" << endl;
                return 0;
            }
        }
    }

    cout << "No" << endl;
    return 0;
}