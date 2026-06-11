#include <bits/stdc++.h>
#include <chrono>
#define watch(x) cout << (#x) << " is " << (x) << endl
#define eps 1e-9
#define f first
#define s second

typedef long long ll;

using namespace std;

int main()

{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    string s;

    cin >> s;

    if (s.size() == 2) cout << s;
    else {

        reverse(s.begin(), s.end());
        cout << s;
    }

    return 0;
}
