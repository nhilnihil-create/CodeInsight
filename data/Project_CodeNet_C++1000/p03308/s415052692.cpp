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
    int n;
    in n;
    vector<int> a(n);
    rep(i,n)in a[i];
    sort(a.begin(), a.end());
    cout<<a[a.size()-1]-a[0]<<endl;
}
