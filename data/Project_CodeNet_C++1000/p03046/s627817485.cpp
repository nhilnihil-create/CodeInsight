//g++ -std=c++17 -Wall t.cpp -o test -lm -g -O2
#include <bits/stdc++.h>
#define ff first
#define ss second
#define ll long long
#define ld long double
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define mt make_tuple
#define pii pair<int, int>
#define vi vector<int>
#define sws ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define teto(a, b) (a+b-1)/(b)

const int MAX = 400010;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const ll LLINF = 0x3f3f3f3f3f3f3f3f;
const ld EPS = 1e-8;
const ld PI = acosl(-1.0);

// End - Template //

using namespace std;

int main()
{
    int m, k;

    cin >> m >> k;
    int p = 1<<m;

    if(m==1)
    {
        if(k>0)
            cout << -1 << endl;
        else
            cout << "0 0 1 1\n";
    }
    else if(k>=p)
        cout << -1 << endl;
    else
    {
        for(int i=p-1;i>=0;i--)
            if(i!=k)
                cout << i << " ";
        cout << k << " ";
        for(int i=0;i<p;i++)
            if(i!=k)
                cout << i << " ";
        cout << k << endl;
    }

    return 0;
}
