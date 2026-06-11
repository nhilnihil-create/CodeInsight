#include<bits/stdc++.h>

using namespace std;

#define ll  long long
#define ld  double

#define sz(x)   (int)x.size()
#define all(x)  x.begin(),x.end()

#define pb  emplace_back
#define X   first
#define Y   second

const int   N   = 1005;
const int   M   = 3e5 + 5;

int main()  {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n;  cin >> n;
    int a;  cin >> a;
    int b;  cin >> b;

    if (a + b - 1 > n || 1ll * a * b < n)   {
        cout << -1;
        return  0;
    }
    for(int i = 1 ; a > 0 ;)    {
        int c = min(b,n - i + 2 - a);

        for(int j = i + c - 1 ; j >= i ; --j)
            cout << j << " ";
        
        i += c;
        a -= 1;
    }
}