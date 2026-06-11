#include <iostream>

using namespace std;

int main(void)
{
    int A, B, answer;
    cin >> A >> B;
    if (A < 6)
    {
        answer = 0;
    }
    else if (A < 13)
    {
        answer = B / 2;
    }
    else
    {
        answer = B;
    }
    cout << answer << endl;
}