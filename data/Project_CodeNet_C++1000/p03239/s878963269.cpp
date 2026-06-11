#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

main()
{
    int n, T, a, b;
    cin >> n >> T;
    vector<pair<int, int>> p;
    for(int i = 0; i < n; i++){
        cin >> a >> b;
        p.push_back(make_pair(a, b));
    }
    sort(p.begin(), p.end());
    for(int i = 0; i < n; i++){
        if(p[i].second <= T){
            cout << p[i].first;
            break;
        }
        else if(i == n-1){
            cout << "TLE";
        }
    }


}





///promy_pompom
//hello world
