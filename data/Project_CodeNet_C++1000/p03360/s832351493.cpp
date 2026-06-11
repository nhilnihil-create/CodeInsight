#include<math.h>
#include <bits/stdc++.h>
#include <algorithm>
#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define ll long long int
#define py printf("Yes\n")
#define pn printf("No\n")
#define in cin>>
using namespace std;
const int INF = 1001001001;

int main()
{
    int a[3],k;
    in a[0]>>a[1]>>a[2]>>k;
    sort(a,a+3);
    cout<<a[0]+a[1]+a[2]*pow(2,k)<<endl;
}
