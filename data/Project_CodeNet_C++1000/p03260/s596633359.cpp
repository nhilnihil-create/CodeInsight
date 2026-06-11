//g++ -std=c++11 -Wall test.cpp -o test -lm -g -O2
#include <bits/stdc++.h>
using namespace std;
#define sws                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define endl '\n'
#define ff first
#define ss second
#define pb push_back
#define vi vector<int>
#define vb vector<bool>
#define vs vector<string>
#define qi queue<int>
#define si stack<int>
#define s string
#define ll long long;

int main()
{
    sws;
    int A, B;
    bool ans = false;
    cin >> A >> B;
    for (int i = 1; i <= B; i++)
    {
        if ((A * B * i) % 2 != 0)
        {
            ans = true;
            break;
        }
    }
    if (ans)
        puts("Yes");
    else
    {
        puts("No");
    }

    return 0;
}