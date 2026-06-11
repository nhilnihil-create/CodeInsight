#include <bits/stdc++.h>
using namespace std;
int H, W;

void aoki(char c, int &l, int &r, int &u, int &d)
{
    if(c == 'L') r = min(W, r+1);
    else if(c == 'R') l = max(1, l-1);
    else if(c == 'U') d = min(H, d+1);
    else if(c == 'D') u = max(1, u-1);
}
void takahashi(char c, int &l, int &r, int &u, int &d)
{
    if(c == 'L') l++;
    else if(c == 'R') r--;
    else if(c == 'U') u++;
    else if(c == 'D') d--;
}

int main()
{
    int n, sr, sc;
    string s, t;
    cin >> H >> W >> n >> sr >> sc >> s >> t;

    int l = 1;
    int r = W;
    int u = 1;
    int d = H;
    for(int i = n-1; i >= 0; i--)
    {
        aoki(t[i], l, r, u, d);
        takahashi(s[i], l, r, u, d);
        if(l > r || u > d)
        {
            cout << "NO" << endl;
            return 0;
        }
    }
    if(sc < l || sc > r || sr < u || sr > d)
    {
        cout << "NO" << endl;
        return 0;
    }
    cout << "YES" << endl;
}
