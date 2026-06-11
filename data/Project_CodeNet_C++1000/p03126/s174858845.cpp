#include<bits/stdc++.h>
#define speed_up ios_base::sync_with_stdio(false); cin.tie(NULL)
#define ll long long
#define ara(A,N) sort(A,A+N)
#define rev(A,N) sort(A,A+N,greater<long long>())
using namespace std;
int main()
{
    speed_up;
    int n, m, cnt = 0;
    cin>>n>>m;
    int a[m+1] = {};
    int i, j;
    i = n;
    while(i--)
    {
        int k;
        cin>>k;
        while(k--)
        {
            cin>>j;
            a[j]++;
        }
    }
    for(i = 1; i<=m; i++)
    {
        if(a[i] == n)
        {
            cnt++;
        }
    }
    cout<<cnt<<endl;
    return 0;

}

