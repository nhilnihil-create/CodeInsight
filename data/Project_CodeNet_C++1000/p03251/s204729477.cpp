#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,m,x,y;
    cin >> n >> m >> x >> y;

    vector<int> xi(n+1);
    vector<int> yi(m+1);
    xi[0]=x;
    yi[0]=y;
    for(int i=1;i<n+1;i++) cin >> xi[i];
    for(int i=1;i<m+1;i++) cin >> yi[i];
    
    sort(xi.begin(),xi.end());
    sort(yi.begin(),yi.end());

    if(xi[n] < yi[0]) cout << "No War" << endl;
    else cout << "War" << endl;
}