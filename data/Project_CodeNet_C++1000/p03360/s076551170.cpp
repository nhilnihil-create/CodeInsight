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
int soma_digitos(int a)
{
    int soma = 0;
    while (a != 0)
    {
        soma += a % 10;
        a /= 10;
    }
    return soma;
}
int main()
{
    sws;
    int k;
    int bb[3];
    cin >> bb[0] >> bb[1] >> bb[2];
    cin >> k;
    while (k--)
    {
        int ind = max(bb[0], max(bb[1], bb[2]));
        int i;
        for (i = 0; i < 3; i++)
        {
            if (bb[i] == ind)
                break;
        }
        bb[i] *= 2;
    }
    int sum = 0;
    for (int i = 0; i < 3; i++)
    {
        sum += bb[i];
    }
    cout << sum << endl;
}