#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cmath>
#include <string>
#include <stdlib.h>
#include <fstream>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <deque>
#include <iterator>
#include <iomanip>
#include <climits>
using namespace std;

int main(){
    long long n, c;
    cin >> n >> c;
    vector<vector<long long> > d(c, vector<long long>(c)), a(n, vector<long long>(n));
    for(int i = 0; i < c; ++i)
        for(int j = 0; j < c; ++j) cin >> d[i][j];

    vector<map<long long, long long> > cnt(3);

    for(int i = 0; i < n; ++i)
        for(int j = 0; j < n; ++j){
            cin >> a[i][j];
            cnt[(i + j + 2) % 3][a[i][j] - 1]++;
        }
    long long ans = 1e9;
    for(int i = 0; i < c; ++i){
        for(int j = 0; j < c; ++j){
            if(i == j) continue;
            for(int x = 0; x < c; ++x){
                if(x == i || x == j) continue;
                long long a1 = 0;
                for(int y = 0; y < c; ++y) a1 += cnt[0][y] * d[y][i];
                for(int y = 0; y < c; ++y) a1 += cnt[1][y] * d[y][j];
                for(int y = 0; y < c; ++y) a1 += cnt[2][y] * d[y][x];
                ans = min(ans, a1);
            }
        }
    }
    cout  << ans;
}