#include <bits/stdc++.h>

using namespace std;

int main ()
{
    int a, b;
    cin >> a >> b;
    int maior = max(a, b);
    if (maior > 8)
        cout << ":(";
    else
        cout << "Yay!";
    cout << endl;
}