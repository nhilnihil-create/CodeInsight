#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
#define REP(i, n) for(int i=0; i<n; i++)
#define REPi(i, a, b) for(int i=int(a); i<int(b); i++)
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
const ll MOD = 1e9+7;

vector<tuple<int, int, int> > ANS;

int main(){
    ll L;
    cin >> L;

    int n = 1;
    int t = 0;
    while(L >= n){
        n *= 2;
        t++;
    }
    n /= 2;

    //cout << n << endl;
    //cout << t << endl;

    n = 1;
    REP(i,t-1){
        ANS.emplace_back(i, i+1, 0);
        ANS.emplace_back(i, i+1, n);
        n *= 2;
    }

    for(int b = t-2; b >= 0; b--){
        bool bit = (L >> b) & 1;
        if(bit){
            ANS.emplace_back(b, t-1, n);
            n += (1LL << b);
        }
    }

    printf("%d %d\n", t, ANS.size());
    for(auto&& ans : ANS){
        int a = get<0>(ans);
        int b = get<1>(ans);
        int c = get<2>(ans);
        printf("%d %d %d\n", a+1, b+1, c);
    }
    return 0;
}
