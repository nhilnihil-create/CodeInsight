#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <unordered_set>
using namespace std;
using ll = long long int;
int main()
{
    int n;
    cin >> n;
    vector<int> slime(n);
    for (size_t i = 0; i < n; i++)
    {
        int ai;
        cin >> ai;
        slime[i] = ai;
    }

    int ans = 0;
    for (size_t i = 1; i < n; i++)
    {
        if (slime[i-1] == slime[i]) {
            ans++;
            slime[i] = 0;
        }
    }
    cout << ans << endl;
        
}