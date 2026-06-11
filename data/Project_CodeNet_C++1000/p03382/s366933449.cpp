#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 200100;
const long long Q = 100000001;
const long long mod = 1e9 + 7;
const long long MAGIC = 30;

using namespace std;

int n;
int a[N];

void solve()
{
        cin >> n;
        for(int i = 1; i <= n; i++){
                cin >> a[i];
        }
        sort(a + 1, a + n + 1);
        int best = 2e9, h;
        int g1 = a[n] / 2, g2 = g1 + a[n] % 2;
        for(int i = 1; i <= n; i++){
                if(min(abs(a[i] - g1), abs(a[i] - g2)) < best){
                        best = min(abs(a[i] - g1), abs(a[i] - g2));
                        h = a[i];
                }
        }
        cout << a[n] << " " << h << "\n";
}

bool mtest = false; int main()
{
        //fin("input.txt");
        //fout("output.txt");
        //fin("maze.in");
        //fout("maze.out");
        ios_base::sync_with_stdio(0);
        int TE = 1;
        if(mtest)
                cin >> TE;
        while(TE--)
                solve();
        return 0;
}
