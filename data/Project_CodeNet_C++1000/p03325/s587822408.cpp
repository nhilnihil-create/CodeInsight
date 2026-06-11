#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
#define endl "\n" 
#define p pair<int, int>
#define arrinp(i, a, start, end); for(ll i = start; i <= end; i++) cin >> a[i];
#define arrout(i, a, start, end); for(ll i = start; i <= end; i++) cout << a[i] << " ";
#define swap(a, b) {a = a + b; b = a - b; a = a - b;
#define forfront(i, start, end) for(ll i = start; i <= end; i++)
#define forback(i, start, end) for(ll i = start; i >= end; i--)
#define out(x) cout << x << " "
#define outline(x) cout << x << endl;
int main()
{
    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int value;
    int temp = 0;
    while (n--)
    {
        cin >> value;
        while(value%2 == 0)
        {
            temp++;
            value /= 2;
        }
    }
    cout << temp << endl;
    return 0;
}