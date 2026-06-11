#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<climits>
#include<cassert>
#include<iostream>
#include<string>
#include<stack>
#include<queue>
#include<vector>
#include<map>
#include<set>
#include<algorithm>
#include<numeric>
#include<bitset>

#define all(c) c.begin(), c.end()
#define rall(c) c.rbegin(), c.rend()
#define debug(x) cerr << #x << ": " << x << endl

using namespace std;

typedef long long ll;
typedef pair<ll, ll> Pll;
typedef pair<int, int> Pii;

const ll MOD = 1000000007;
const int INF = (1 << 30);
const long double EPS = 1e-10;
const int dyx[4][2] = {
    { 0, 1}, {-1, 0}, {0,-1}, {1, 0}
};

bool check(int n, vector<int> a, int x) {
    map<int, int> mp;
    mp[a[1]-1] = 0;

    // cerr << "x: " << x << endl;
    for(int i=1;i<=n;++i) {
        // cerr << i << endl;
        vector<int> to_erase;
        if(a[i-1] < a[i]) {
            map<int, int> mp2;
            for(auto itr=mp.begin();itr!=mp.end();++itr) {
                if(itr->first < a[i]) {
                    mp2[itr->first] = itr->second;
                } else {
                    break;
                }
            }
            swap(mp, mp2);
        } else if(a[i-1] == a[i]) {
            bool added = false;
            for(int j=a[i]-1;j>=0;--j) {
                if(mp.find(j) == mp.end()) {
                    if(x == 1) return false;
                    mp[j] = 1;
                    added = true;
                    break;
                } else if(mp[j] != x-1) {
                    ++mp[j];
                    added = true;
                    break;
                } else {
                    to_erase.push_back(j);
                }
            }
            if(!added) return false;
        } else {
            bool added = false;
            for(int j=a[i]-1;j>=0;--j) {
                if(mp.find(j) == mp.end()) {
                    if(x == 1) return false;
                    mp[j] = 1;
                    added = true;
                    break;
                } else if(mp[j] != x-1) {
                    ++mp[j];
                    added = true;
                    break;
                } else {
                    to_erase.push_back(j);
                }
            }
            if(!added) return false;

            for(auto itr=mp.begin();itr!=mp.end();++itr) {
                if(itr->first >= a[i]) {
                    to_erase.push_back(itr->first);
                }
            }
        }

        for(int e: to_erase) mp.erase(e);

        // for(auto itr=mp.begin();itr!=mp.end();++itr) {
        //     cerr << itr->first << " " << itr->second << endl;
        // }
    }

    return true;
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n+1, 0);
    for(int i=1;i<=n;++i) cin >> a[i];
    
    int ng = 0, ok = 300000;
    while(ok-ng > 1) {
        // cerr << endl << ng << " " << ok << endl;
        int mid = (ok + ng) / 2;
        if(check(n, a, mid)) {
            ok = mid;
        } else {
            ng = mid;
        }
    }
    cout << ok << endl;
}
