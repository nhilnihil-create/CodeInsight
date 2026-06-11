#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using PII = std::pair<int, int>;
using PLL = std::pair<ll, ll>;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)


const int mod = 1e9 + 7;

int main()
{

#ifdef DEBUG
    cout << "DEBUG MODE" << endl;
    ifstream in("input.txt"); //for debug
    cin.rdbuf(in.rdbuf());    //for debug
#endif

    int n, left, right, mid;
    cin >> n;
    string s, seat[n+1];

    left = 0; right = n;

    cout << 0 << endl;
    cin >> s;
    if (s == "Vacant")
        return 0;
    seat[0] = seat[n] = s;

    while(1)
    {
        mid = (left + right) / 2;
        cout << mid << endl;
        cin >> s;
        if (s == "Vacant")
            return 0;
        seat[mid] = s;

        if ((mid  - left) % 2 == 0 && seat[mid] != seat[left])
            right = mid;
        else if ((mid  - left) % 2 == 0 && seat[mid] == seat[left])
            left = mid;
        else if ((mid  - left) % 2 != 0 && seat[mid] != seat[left])
            left = mid;
        else if ((mid  - left) % 2 != 0 && seat[mid] == seat[left])
            right = mid;
    }



    return 0;
}