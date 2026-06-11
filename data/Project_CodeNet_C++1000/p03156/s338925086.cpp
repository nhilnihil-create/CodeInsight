#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <stdio.h>
#include <queue>
#include <climits>
#include <map>
#include <set>
const int mod = 1e9 + 7;
const int inf = 1 << 20;
const long long INF = 1LL << 60;
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
using namespace std;


int main()
{
    int n,a,b;
    cin >> n >> a >> b;
    int p[n];
    for(int i = 0; i < n; i++){
        cin >> p[i];
    }
    sort(p,p+n);
    int x = 0,y = 0,z = 0;
    for(int i = 0; i < n; i++){
        if(p[i] <= a) x++;
        else if(p[i] >= a+1 && p[i] <= b) y++;
        else if(p[i] >= b+1) z++;
    }
    cout << min({x,y,z});
}
