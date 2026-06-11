#include <bits/stdc++.h>

using namespace std;

int main()
{
    string S, A;
    cin >> S;
    int Difference, B;
    vector<int> v;

    for (int i = 0; i + 2 < S.length(); i++)
    {
        A = S.substr(i, 3);
        B = stoi(A);
        Difference = B - 753;
        Difference = abs(Difference);
        v.push_back(Difference);
    }

    sort(v.begin(), v.end());

    cout << v[0];
}