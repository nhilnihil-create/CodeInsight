#include <bits/stdc++.h>
using namespace std;

int64_t mod = 1000000007;
int64_t large = 9223372036854775807;
double PI = 3.141592653589793;

int main()
{
    int A, B;
    string S;
    cin >> A >> B >> S;
    bool x = true;
    for (int i = 0; i < A; i++)
        if (!isdigit(S[i]))
            x = false;
    if(S[A]!='-')
        x = false;
    for (int i = A + 1; i < S.size(); i++)
        if (!isdigit(S[i]))
            x = false;
    cout << (x ? "Yes" : "No");
}