#include <bits/stdc++.h>
#define ll long long

using namespace std;

bool is_odd(int number) {
        if (number%2 == 0) {
                return false;
        }
        return true;
}

int main() {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        int a, b;

        cin >> a >> b;

        int n;

        for(int i = min(a,b); i <= max(a,b); i++) {
                n = a * i * b;
                if(is_odd(n)) {
                        cout << "Yes" << endl;
                        return 0;
                }
        }

        cout << "No" << endl;
        return 0;
}