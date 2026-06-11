#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
    int n, l, s = 0, m = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &l);
        if (l > m) m = l;
        s += l;
    }
    cout << ((m*2 < s) ? "Yes" : "No");
}