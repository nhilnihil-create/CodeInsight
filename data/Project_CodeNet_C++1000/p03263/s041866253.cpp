#include<bits/stdc++.h>

using namespace std;

#define Q int t; scanf("%d", &t); for(int q=1; q<=t; q++)
typedef long long int lli;
typedef pair<int, int> pi;

int a[501][501];

int main()
{
    int n, m;
    cin >> n >> m;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            cin >> a[i][j];
        }
    }
    vector<pair<pi, pi> > v;
    int t = 0;
    for(int i=1; i<=n; i++){
        for(int j=1; j<m; j++){

            t += (a[i][j]%2);
            if(t%2){
                v.push_back({{i, j}, {i, j+1}});
            }
        }
        if(i==n)break;

        t += (a[i][m]%2);
        if(t%2){
            v.push_back({{i, m},{i+1, m}});
        }
        i++;
        for(int j=m; j>1; j--){
            t += (a[i][j]%2);
            if(t%2){
                v.push_back({{i, j}, {i, j-1}});
            }
        }
        if(i==n)break;
        t += (a[i][1]%2);
        if(t%2){
            v.push_back({{i, 1},{i+1, 1}});
        }
    }
    cout << v.size() << "\n";
    for(auto x: v){
        cout << x.first.first << " " << x.first.second << " " << x.second.first << " " << x.second.second << "\n";
    }

    return 0;
}
