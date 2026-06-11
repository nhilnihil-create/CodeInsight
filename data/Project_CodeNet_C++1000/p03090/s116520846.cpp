#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin>>n;

    vector<pair<int, int>>  edges;

    bool b = n%2;
    n -= b;

    for (int i=1; i<=n; i++)
        for (int j=i+1; j<=n; j++)
            if (i+j!=n+1)
                edges.push_back({i, j});

    if (b) {
        for (int i=1; i<=n; i++)    edges.push_back({i, n+1});
    }
    cout<<edges.size()<<endl;
    for (auto pr: edges)
        cout<<pr.first<<" "<<pr.second<<"\n";

}
