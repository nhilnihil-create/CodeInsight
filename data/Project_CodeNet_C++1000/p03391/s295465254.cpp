#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <stdio.h>
#include <queue>
#include <stack>
#include <climits>
#include <map>
#include <set>

using namespace std;

typedef long long ll;
typedef pair<int, int> P;

const ll mod = 1000000007;
const int inf = 1e9;
const long long INF = 1LL << 60;

int main()
{
    int n;
    cin >> n;
    ll a[n],b[n];
    for(int i = 0; i < n; i++){
        cin >> a[i] >> b[i];
    }
    bool same = true;
    for(int i = 0; i < n; i++){
        if(a[i] != b[i]) same = false;
    }
    if(same){
        cout << 0 << endl;
    }else{
        ll sum = 0,sub = INF;
        for(int i = 0; i < n; i++){
            sum += a[i];
            if(sub > b[i] && a[i] > b[i]) sub = b[i];
        }
        cout << sum - sub << endl;
    }
}