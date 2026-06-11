#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <numeric>
#include <array>
#include <set>
#include <map>
#include <queue>
using namespace std;
 
#define REP(i,n) for(int (i)=0;(i)<(int)(n);(i)++)
#define RREP(i,n) for(int (i)=(int)(n)-1;i>=0;i--)
#define REMOVE(Itr,n) (Itr).erase(remove((Itr).begin(),(Itr).end(),n),(Itr).end())
typedef long long ll;

int main() {

    int cnt[3] = {};
    string s; cin >> s;
    REP(i,s.size()) cnt[s[i] - 'a']++;

    sort(cnt, cnt + 3);
    if (abs(cnt[0] - cnt[2]) <= 1) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}