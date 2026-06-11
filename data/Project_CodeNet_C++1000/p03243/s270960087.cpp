#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N;
    string a, Sum;
    cin >> N;

    for (int i = 1; i <= 9; i++)
    {
        a = to_string(i);
        Sum = a + a + a;
        int Sum2 = stoi(Sum);

        if (Sum2 >= N)
        {
            cout << Sum2;
            break;
        }
    }
}