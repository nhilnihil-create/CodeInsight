//  ©   ___MRX___

#include <bits/stdc++.h>
    using namespace std;

#define ll long long int

int main()
{
    int a, b, k, i;
    cin >> a >> b >> k;

    vector<int> vec;

    for(i = min(a, b); i > 0; i--) {
        if(a % i == 0 && b % i == 0) {
            vec.push_back(i);
        }
    }

    cout << vec[k - 1] << '\n';

    return 0;
}
