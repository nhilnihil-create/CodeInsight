#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N,a = 0;
    long A,O[100];
    vector<long> v;
    cin >> N;

    while (cin >> A)
    {
        O[a] = A;
        v.push_back(O[a]);
        a++;
    }

    sort(v.begin(),v.end());

    cout << v[v.size() - 1 ] -v[0];

}