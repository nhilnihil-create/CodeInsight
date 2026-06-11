#include<bits/stdc++.h>

#define fi first
#define se second
#define ll long long
#define pb push_back
#define mp make_pair
#define mt make_tuple

using namespace std;

set<pair<int, int>> veze;

void connect(int n)
{
    for(int i = 1; i < n; i++)
        for(int j = i + 1; j <= n; j++)
            veze.insert(mp(i,j));
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    connect(n);
    int S = n*(n+1)/2;
    if(n % 2 == 0)
        for(int i = 1; i <= n / 2; i++) veze.erase(mp(i, n - i + 1));
    else
        for(int i = 1; i <= n / 2; i++) veze.erase(mp(i, n - i));
    cout << veze.size() << "\n";
    for(set<pair<int,int>>::iterator it = veze.begin(); it != veze.end(); it++)
        cout << it->first << " " << it->second << "\n";

    return 0;
}
