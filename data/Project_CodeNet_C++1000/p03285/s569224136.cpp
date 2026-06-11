#include <iostream>
using namespace std;

int main()
{
    int N;
    cin >> N;
    int a = 0;
    int b = 0;
    bool answer = false;
    while (true)
    {
        if (4 * a > N)
        {
            break;
        }
        while (true)
        {
            if (4 * a + 7 * b > N)
            {
                b = 0;
                break;
            }
            if (4 * a + 7 * b == N)
            {
                b = 0;
                answer = true;
                break;
            }
            ++b;
        }
        ++a;
    }
    if (answer == true)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
}