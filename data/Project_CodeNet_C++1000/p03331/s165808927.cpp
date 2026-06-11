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
    int n;
    cin >> n;
    int sum = n + 1;
    for (int i = 1, j = n - 1; i <= n && j > 0; i++, j--)
    {
        if (soma_digitos(i) + soma_digitos(j) < sum)
        {

            sum = soma_digitos(i) + soma_digitos(j);
        }
    }
    cout << sum << endl;
}