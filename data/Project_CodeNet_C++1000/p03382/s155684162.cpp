#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <map>
#include <set>
#include <algorithm>
#include <vector>
#include <cmath>
#include <ctime>
#include <queue>
#include <cassert>
using namespace std;

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())

typedef long long ll;
typedef pair<int,int> PII;
typedef vector<int> VI;

const int N = 200005;

int a[N], n;

//your code goes there
int main()
{

        ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
        cin >> n;
        for(int i = 1; i <= n; ++i) cin >> a[i];
        sort(a+1,a+1+n);
        int ans = -1, Min = 1e9;
        for(int i = 1; i <= n; ++i) if(abs(a[i]-(a[n]+1)/2) < Min) Min = abs(a[i]-(a[n]+1)/2), ans = i;
        cout << a[n] << ' ' << a[ans] << endl;
        return 0;
}
