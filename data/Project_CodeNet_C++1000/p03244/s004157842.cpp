#include <numeric>
#include <iostream>
#include <array>
#include <string>
#include <vector>
#include <cassert>
#include <algorithm>
#include <math.h> 
#include <set>
#include <map>
#include <utility>
#include <deque>
#include <queue>


using namespace std;

#define ll long long int
#define rep(i, n) for(ll i = 0; i < n; i++)
#define repp(i, n) for(ll i = 1; i <= n; i++)
#define sort(v) sort((v).begin(), (v).end())
#define riverse(v) reverse((v).begin(), (v).end())
#define pb push_back
#define mp make_pair
#define all(a)  (a).begin(),(a).end()
using vi = vector<int>;
using vs = vector<string>;
using vll = vector<ll>;
using vvi = vector<vi>;
using vvvi = vector<vvi>;
const ll MOD = 1e9 + 7;
vi alphabet = { 'a','b','c','d','e','f','g','h','i','j','k','l','m',
               'n','o','p','q','r','s','t','u','v','w','x','y','z' };

int main() {
    int N;
    cin >> N;
    vi odd(N / 2);
    vi even(N / 2);
    rep(i, N/2) {
        cin >> odd[i];
        cin >> even[i];
    }
    map<int, int> o;
    map<int, int> e;
    rep(i, N / 2) {
        if (o.count(odd[i])) o[odd[i]]++;
        else o[odd[i]] = 1;
        if (e.count(even[i])) e[even[i]]++;
        else e[even[i]] = 1;
    }
    int co = 0;
    int ce = 0;
    int oind = 0;
    int eind = 0;
    for (auto x : o) {
        int i = x.second;
        if (i >= co) {
            co = i;
            oind = x.first;
        }
    }
    for (auto x : e) {
        int i = x.second;
        if (i >= ce) {
            ce = i;
            eind = x.first;
        }
    }
    if (oind != eind) {
        int ao = N / 2 - co;
        int ae = N / 2 - ce;
        cout << ao + ae << endl;
    }
    else {
        if (co > ce) {
            e[eind] = 0;
            ce = 0;
            for (auto x : e) {
                int i = x.second;
                if (i >= ce) {
                    ce = i;
                    eind = x.first;
                }
            }
            cout << N - ce - co << endl;
        }
        else if (co < ce) {
            o[oind] = 0;
            co = 0;
            for (auto x : o) {
                int i = x.second;
                if (i >= co) {
                    co = i;
                    oind = x.first;
                }
            }
            cout << N - ce - co << endl;
        }
        else {
            int coo = co;
            int cee = ce;
            
            e[eind] = 0;
            ce = 0;
            for (auto x : e) {
                int i = x.second;
                if (i >= ce) {
                    ce = i;
                    eind = x.first;
                }
            }
            o[oind] = 0;
            co = 0;
            for (auto x : o) {
                int i = x.second;
                if (i >= co) {
                    co = i;
                    oind = x.first;
                }
            }
            if (co >= ce)cout << N - cee - co << endl;
            else cout << N - coo - ce << endl;
        }
    }
}
