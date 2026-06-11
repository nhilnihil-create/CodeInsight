#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define f first
#define s second
#define pb push_back

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int a, b, road, area;
    cin >> a >> b;
    area = a*b;
    road = a+b-1;
    area -= road;
    cout << area << endl;
    return 0;
}

