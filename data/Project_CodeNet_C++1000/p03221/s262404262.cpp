#include <iostream>
#include <cmath>
#include <cstdio>
#include <set>
#include <string>
#include <algorithm>
#include <vector>
#include <bitset>
#include <iomanip>
#include <map>
#include <queue>
#include <numeric>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::bitset;

#define rep(i,n)    for(int i=0; i<(int)n; i++)
#define reps(i,s,e) for(int i=s; i<(int)e; i++)
#define coutd(i) cout << std::fixed << std::setprecision(i)
typedef long double ld;
typedef long long ll;
typedef vector<int> vint;
typedef vector<ll> vll;
typedef std::pair<int, int> pii;
typedef std::pair<ll, ll> pll;

template<class T>
using Graph = vector<vector<T>>;

const int INT_BIG = 1<<28;

struct City {
    int cityNum;
    ll id;
    int prefNum;
    ll year;
};

int main() {
    int N, M;
    cin >> N >> M;
    vector<City> cityList(M);
    rep(i, M) {
        int p, y;
        cin >> p >> y;
        City c;
        c.cityNum = i;
        c.prefNum = p;
        c.year = y;
        cityList[i] = c;
    }

    auto func = [](City a, City b) {
        return ((a.prefNum == b.prefNum) ? a.year < b.year : a.prefNum < b.prefNum);
    };
    std::sort(cityList.begin(), cityList.end(), func);

    ll nowPref = 1;
    ll nowCity = 1;
    rep(i, M) {
        City &c = cityList[i];
        if (c.prefNum != nowPref) {
            nowPref = c.prefNum;
            nowCity = 1;
        }
        // cout << c.year << endl;
        // cout << nowPref * 1000000ll + nowCity << endl;
        c.id = nowPref * 1000000ll + nowCity;
        nowCity++;
    }

    auto func2 = [](City a, City b) {
        return a.cityNum < b.cityNum;
    };
    std::sort(cityList.begin(), cityList.end(), func2);
    rep(i, M) {
        char str[13];
        // cout << cityList[i].cityNum << endl;
        sprintf(str, "%012lld", cityList[i].id);
        cout << str << endl;
    }
}