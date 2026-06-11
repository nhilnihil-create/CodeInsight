#include <bits/stdc++.h>
using namespace std;
#define rep(i, c) for (int i = 0; i < (int)c; i++)
int main()
{
    int n;
    scanf("%d", &n);
    vector<int> vec(n);
    rep(i, n) scanf("%d", &vec[i]);
    sort(vec.begin(), vec.end());
    int temp = 0;
    rep(i, n - 1) temp += vec[i];
    if(vec[n - 1] < temp) printf("Yes\n");
    else printf("No\n");
    return 0;
}