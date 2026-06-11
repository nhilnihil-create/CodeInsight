#include <bits/stdc++.h>
#define PI 3.1415926535897
using namespace std;
typedef long long ll;
const int INF = 1000000000;
const ll LINF = 1000000000000000000; //1e18
const double EPS = 1e-10;

int main(void)
{
    int N;
    cin >> N;

    string name;
    char head;
    map<char, ll> march;
    for (int i = 0; i < N; i++)
    {
        cin >> name;
        head = name[0];
        if (head == 'M' || head == 'A' || head == 'R' || head == 'C' || head == 'H')
        {
            march[head]++;
        }
    }

    if (march.size() < 3)
    {
        printf("0\n");
        return (0);
    }

    ll ans = 0;
    string word = "MARCH";

    for (int i = 0; i < 5; i++)
    {
        for (int j = i + 1; j < 5; j++)
        {
            for (int k = j + 1; k < 5; k++)
            {
                ans += march[word[i]] * march[word[j]] * march[word[k]];
            }
        }
    }

    // for (auto itr = march.begin(); itr != march.end(); itr++)
    // {
    //     cout << itr->first << " : " << itr->second << endl;
    // }

    cout << ans << endl;
    return (0);
}