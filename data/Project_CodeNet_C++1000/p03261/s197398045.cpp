#include <bits/stdc++.h>
#define rep0(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i <= (n); ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
typedef tuple<string, int, int> TU;
typedef tuple<int, int, int> TI;

int main()
{
    int N;
    cin >> N;
    char siri;
    bool res = true;
    set<string> set;
    rep0(i, N)
    {
        string input;
        cin >> input;
        set.insert(input);
        if (i == 0)
        {
            siri = input[0];
        }
        if (siri != input[0])
        {
            res = false;
            break;
        }
        siri = input[input.length() - 1];
    }
    if (res && set.size() == N)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
}
