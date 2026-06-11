#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
    int n, a, b;
    cin >> n >> a >> b;
    int ans = 0;

    for (int i = 1; i <= n; i++) {
        string num_str = to_string(i);
        int sum = 0;
        for (int j = 0; j < num_str.size(); j++) {
            sum = sum + (int)(num_str[j] - '0');
        }

        if (a <= sum && sum <= b) ans = ans + i;
    }

    cout << ans;
}