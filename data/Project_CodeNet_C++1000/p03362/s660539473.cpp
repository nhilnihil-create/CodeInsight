#include <cstdio>
#include <algorithm>
#include <vector>
#include <iostream>
#include <map>
#include <queue>
#include <cstring>
#include <string>
#include <cstdlib>
#include <cmath>
using namespace std;
#define inf 1 << 28
const int maxn = 1e5 + 5;
typedef long long ll;

int const N = 55557;
bool vis[N];
void isprime()
{
    memset(vis, false, sizeof vis);
    vis[1] = true;
    for (int i = 2; i < 55555; i++)
    {
        if (!vis[i])
        {
            for (int j = i + i; j < 55555; j += i)
            {
                vis[j] = true;
            }
        }
    }
}
int n;
void solv()
{
    cout << 7 <<' ';
    int sum=2,ans=1;
    for (int i=12;i<55555;i++)
    {
        if(!vis[i]&&i%10==7)
        {
            cout<<i<<' ';
            ans++;
        }
        if(ans==n)
        break;
    }
    cout<<endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    isprime();
    cin >> n;
    solv();
}