#include <iostream>
#include <cstring>
#include <cmath>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <set>
#include <map>
#include <iterator>
#include <stack>
#include <string.h>
#include <cstdlib>
#include <queue>
#include <list>
#include <string>

using namespace std;


int main()
{
    int n,m;
    vector<pair<long long,int>> x;
    
    cin >> n >> m;
    long long k;
    for (int i = 0;i < n;i++){
        cin >> k;
        x.push_back({k,1});
    }
    long long q;
    int p;
    for (int i = 0;i < m;i++){
        cin >> p >> q;
        x.push_back({q,p});
    }
    sort(x.begin(),x.end());
    
    long long ans = 0;
    int j = 0;
    for (int i = 1;i <= n;i++){
        ans += x[n+m-i].first*min(n-j,x[n+m-i].second);
        j += x[n+m-i].second;
        if (j >= n){
            break;
        }
    }
    cout << ans << endl;
}
