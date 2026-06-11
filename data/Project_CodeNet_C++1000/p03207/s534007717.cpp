#include<math.h>
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define    ll   long long int
#define    py   printf("Yes\n")
#define    pn   printf("No\n")
using namespace std;

ll hako[200000];
int main()
{
    int n,tmp=0;
    cin>>n;
    int p[n];
    for(int i=0;i<n;i++)
    {
      cin>>p[i];
    }
    sort(p,p+n);
    for(int i=0;i<n-1;i++)
    {
      tmp+=p[i];
    }
    cout<<tmp+p[n-1]/2<<endl;
    return 0;
}
