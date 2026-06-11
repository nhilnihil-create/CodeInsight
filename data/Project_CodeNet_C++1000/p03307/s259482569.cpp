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
typedef struct
{
    int start;
    int end;
    int pos;
} task_t;
bool organiza(pair<char, int> a, pair<char, int> b)
{
    return a.ss < b.ss;
}
bool compara(task_t a, task_t b)
{
    return a.start < b.start;
}
void mostra(vector<pair<char, int>> v)
{
    for (int i = 0; i < (int)v.size(); i++)
    {
        cout << v[i].ff;
    }
    cout << endl;
}
int main()
{
    sws;
    int n;
    cin >> n;
    int i = n;
    while (true)
    {
        if (i % 2 == 0 && i % n == 0)
            break;
        i++;
    }
    cout << i << endl;
}