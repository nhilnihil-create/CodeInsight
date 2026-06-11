#include<bits/stdc++.h>

#define fi first
#define se second
#define ll long long
#define pb push_back
#define mp make_pair
#define mt make_tuple

using namespace std;

int stepen(int a, int k)
{
    if(k == 0) return 1;
    int r = stepen(a, k / 2);
    r *= r;
    if(k % 2 == 1) r *= a;
    return r;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int m, k;
    cin >> m >> k;
    int B = stepen(2, m) - 1;
    if(k > B || (k ==1 && m == 1))
    {
        cout << -1;
        return 0;
    }
    if(k == 0 && m == 1) {cout << "1 1 0 0"; return 0;}

    for(int i = 0; i <= B; i++)
    {
        if(i == k) continue;
        cout << i << " ";
    }
    cout << k << " ";
    for(int i = B; i >= 0; i--)
    {
        if(i == k) continue;
        cout << i << " ";
    }
    cout << k << " ";

    return 0;
}
