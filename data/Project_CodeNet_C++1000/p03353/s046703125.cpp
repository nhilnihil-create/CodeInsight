#include <bits/stdc++.h>
#define INF 1e9
using namespace std;

#define REPR(i,n) for(int i=(n); i >= 0; --i)
#define FOR(i, m, n) for(int i = (m); i < (n); ++i)
#define REP(i, n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define ALL(a)  (a).begin(),(a).end()

template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return true; } return false; }
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return true; } return false; }
int gcd(int a,int b){return b?gcd(b,a%b):a;}
typedef long long ll;
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}

void printVec(std::vector<string> &vec) {
    std::cout << "";
    for (auto it = vec.begin(); it != vec.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

int main() {
    string s;
    cin >> s;
    int K;
    cin >> K;
    vector<string> subs;
    REP(i,s.size()) {
        FOR(j,1,min(6,int(s.size()-i+1))) {
            subs.push_back(s.substr(i,j));
        }
    }
    sort(ALL(subs));
    subs.erase(unique(ALL(subs)),subs.end());

    // printVec(subs);
    cout << subs[K-1]<< endl;

    return 0;
}
