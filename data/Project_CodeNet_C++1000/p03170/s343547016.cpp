#include <bits/stdc++.h>
#define maxn 100005
#define fto(i,j,h)   for (int i=j; i<=h; ++i)
#define fdto(i,j,h) for (int i=j; i>=h;  --i)
#define ll long long
#define pii pair<int, int>
#define fi first
#define se second
using namespace std;

int n, m, a[maxn];
int F[maxn][3];
int main()
{
    ios_base::sync_with_stdio(0);
    cin >> n >> m;
    fto(i,1,n)    cin >> a[i];
    sort(a+1, a+n+1);
    fto(i,1,m)    F[i][0] = F[i][1] = -1e9;
    fto(i,0,a[1]-1)    F[i][0] = F[i][1] = 0;
    fto(i,a[1],m){
       fto(j,1,n){
          if (a[j] > i)    break;
          F[i][0] = max(F[i][0], 1 - F[i-a[j]][1]);
          F[i][1] = max(F[i][1], 1 - F[i-a[j]][0]);
       }
    }
    if (F[m][0] > 0)    cout << "First";
    else cout << "Second";
}
