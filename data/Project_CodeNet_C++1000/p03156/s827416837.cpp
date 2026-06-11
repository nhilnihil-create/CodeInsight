#include<bits/stdc++.h>

using namespace std;
using ll = long long;



int main()
{
    int n,a,b;
    cin >> n >> a >> b;
    vector<int> p(n);
    vector<bool> seen(n);
    for(int i = 0; i < n; i++)cin >> p[i];
    int x = 0, y = 0, z = 0;

    for(int i = 0; i < n; i++){
        if(p[i] <= a)x++;
        else if(p[i] > b)y++;
        else z++;
    }
    cout << min({x,y,z}) << endl;

}