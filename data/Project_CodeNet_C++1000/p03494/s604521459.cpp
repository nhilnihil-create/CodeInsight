
#include <bits/stdc++.h>
using namespace std;
int count(int n)
{
    int c = 0;
    while (!(n % 2) && n > 0)
    {
        c++;
        n /= 2;
    }
    return c;
}

int main()
{
    int n;
    int ans = INT_MAX;
    cin >> n;
    for (int i = 0; i < n; i++){
        int curr;
        cin >> curr;
        ans = min(ans,count(curr));
    }
    cout << ans;
}