/*BISMILLAH
THE WHITE WOLF
NO DREAM IS TOO BIG AND NO DREAMER IS TOO SMALL*/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef vector<long long> vll;
typedef vector<int> vi;

#define io ios_base::sync_with_stdio(false)
#define pb push_back
#define mod  1000000007LL
#define PI 2*acos(0.0)


int main()
{
    io;
    int n;
    cin>>n;
    vi pos(n);
    for(int i = 0; i< n;i++)
    {
        int x;
        cin>>x;
        pos[--x] = i;
    }
    int ans = 1, sor = 1;
    for(int i = 1; i<n; i++)
    {
        if(pos[i] > pos[i-1])
            sor++;
        else
            sor = 1;
        ans = max(ans, sor);
    }
    cout<<n - ans;
    return 0;
}