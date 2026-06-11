//  ©   ___MRX___

#include <bits/stdc++.h>
    using namespace std;

#define ll long long int

int main()
{
    int n, i, total = 0, largest;
    cin >> n;
    vector<int> pg(n);

    for(i = 0; i < n; i++) {
        cin >> pg[i];
        total += pg[i];
    }

    largest = *max_element(pg.begin(), pg.end());

    largest < total - largest ? cout << "Yes" : cout << "No";
    cout << '\n';

    return 0;
}
