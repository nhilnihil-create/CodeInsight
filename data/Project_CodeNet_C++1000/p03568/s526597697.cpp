#include<bits/stdc++.h>

using ll = long long;
using namespace std;
vector<int> a;
int cnt = 0;
int n;


void dfs(int depth, ll cur)
{
    if(depth == n){
        cnt += (cur % 2 == 0);
        return;
    }

    dfs(depth + 1, cur * (a[depth] + 1));
    dfs(depth + 1, cur * (a[depth]));
    dfs(depth + 1, cur * (a[depth] - 1));
}




int main()
{
    cin >> n;
    a.resize(n);
    for(int i = 0; i < n; i++)cin >> a[i];
    dfs(0,1);
    cout << cnt << endl;

}