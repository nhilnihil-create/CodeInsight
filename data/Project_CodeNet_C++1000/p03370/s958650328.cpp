#include <iostream>
#include <climits>

using namespace std;

int main()
{
    int q, m;
    cin >> q >> m;

    int min_ = INT_MAX;

    for(int i=0, val; i<q; i++) {
        cin >> val;
        m -= val;
        min_ = min(min_, val);
    }

    cout << q + m/min_ << '\n';

    return 0;
}
