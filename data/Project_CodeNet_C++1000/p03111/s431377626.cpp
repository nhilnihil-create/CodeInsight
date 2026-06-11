#include <iostream>
#include <algorithm>
using namespace std;
int ans = -1;
void cost(int bam[], int n, int a, int b, int c, int x, int o, int t, int w)
{
    if(x == n)
    {
        if(o == -1 || t == -1 || w == -1)
        {
            return;
        }
        int sub = (o + t + w) * 10 + abs(a) + abs(b) + abs(c);
        if(ans == -1)
        {
            ans = sub;
        }
        if(sub < ans)
        {
            ans = sub;
        }
        return;
    }
    a -= bam[x];
    o++;
    cost(bam, n, a, b, c, x+1, o, t, w);
    o--;
    a += bam[x];
    b -= bam[x];
    t++;
    cost(bam, n, a, b, c, x+1, o, t, w);
    t--;
    b += bam[x];
    c -= bam[x];
    w++;
    cost(bam, n, a, b, c, x+1, o, t, w);
    w--;
    c += bam[x];
    cost(bam, n, a, b, c, x+1, o, t, w);
}
int main()
{
    int n, a, b, c;
    cin >> n >> a >> b >> c;
    int bam[n];
    for(int i = 0; i < n; i++)
    {
        cin >> bam[i];
    }
    cost(bam, n, a, b, c, 0, -1, -1, -1);
    cout << ans << endl;
    return 0;
}
