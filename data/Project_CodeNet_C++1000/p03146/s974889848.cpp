#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(void)
{
    vector<int> a;
    int s;
    cin >> s;
    a.push_back(s);
    int i;
    for (i = 2;i <= 1000000;i++)
    {
        int an = (a.back() % 2 == 0)? a.back() / 2 : 3 * a.back() + 1;
        auto re = find(a.begin(), a.end(), an);
        if(re != a.end()) break;
        a.push_back(an);
    }

    cout << i << endl;
    
    return 0;
}
