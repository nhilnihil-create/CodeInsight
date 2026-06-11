#include<math.h>
#include <bits/stdc++.h>
#include <algorithm>
#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define ll long long int
#define py printf("Yes\n")
#define pn printf("No\n")
#define in cin>>
using namespace std;
int INF = 1001001001;

int main()
{
    string s,t;
    in s>>t;
    sort(s.begin(), s.end());
    sort(t.begin(), t.end(), greater<int>());
    if(s<t)py;
    else pn;

}
