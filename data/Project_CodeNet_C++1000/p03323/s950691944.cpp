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
    int a, b;
    cin >> a >> b;
    s ans = (a > 8 || b > 8) ? ":(" : "Yay!";
    cout << ans << endl;
}