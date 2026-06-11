#include <bits/stdc++.h>
using namespace std;

const string JpyStr = "JPY";
const int BtcJpyRate = 380000;

int main()
{
    int n;
    cin >> n;

    double sum = 0;

    for (int i = 0; i < n; ++i)
    {
        double input;
        cin >> input;

        string unit;
        cin >> unit;

        sum += (unit == JpyStr ? input : input * BtcJpyRate);
    }

    cout << setprecision(12) << fixed;
    cout << sum << endl;
}