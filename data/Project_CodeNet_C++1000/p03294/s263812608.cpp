#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define MOD 1000000007

int main()
{
    int N;
    cin >> N;
    vector<int> v;
    ll sum = 0;
    for (int i = 0; i < N; ++i)
    {
        ll temp;
        cin >> temp;
        sum += temp;
        v.push_back(temp);
    }
    cout << sum - N << endl;
}
