#include <iostream>
#include <map>
#include <algorithm>
#define mp make_pair
using namespace std;

long long n;
char S[50];
long long p[50];
map < pair <string, string>, long long> st, dr;

void bkt(long long half, long long poz)
{
    if (poz > n)
    {
        string red = "", blue = "";
        for (long long i = (half - 1) * n + 1; i <= half * n; i++)
            if (p[i] == 1)
                red += S[i];
            else
                blue += S[i];
        if (half == 1)
            st[mp(red, blue)]++;
        else
            dr[mp(red, blue)]++;
        return;
    }

    for (long long i = 1; i <= 2; i++)
    {
        p[(half - 1) * n + poz] = i;
        bkt(half, poz + 1);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (long long i = 1; i <= 2 * n; i++)
        cin >> S[i];

    reverse(S + n + 1, S + 2 * n + 1);

    bkt(1, 1);
    bkt(2, 1);

    //for (auto nr: dr)
      //  cout << nr.first.first << ", " << nr.first.second << ": " << nr.second << "\n";

    long long total = 0;
    for (auto nr: st)
        total += nr.second * dr[nr.first];
    cout << total;

    return 0;
}
