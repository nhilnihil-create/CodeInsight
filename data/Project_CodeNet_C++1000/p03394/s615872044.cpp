#include <bits/stdc++.h>
using namespace std;
#define SELECTER(_1, _2, _3, SELECT, ...) SELECT
#define REP1(i, n) for(int i=0; i<n; i++)
#define REP2(i, a, b) for(int i=a; i<b; i++)
#define REP(...) SELECTER(__VA_ARGS__, REP2, REP1,) (__VA_ARGS__)
#define MOD 1'000'000'007

template <class T> ostream& operator<<(ostream& os, const vector<T>& v){ os << "{"; for(size_t i=0; i<v.size(); i++) os << v[i] << (i+1==v.size() ? "" : ", "); os << "}"; return os; }
template <class T, class U> ostream& operator<<(ostream& os, const pair<T, U>& p){ return os << "{" << p.first << ", " << p.second << "}"; }

int oddnize(int n){
    return n-(n%2==0);
}

int main(){
    int N;
    cin >> N;
    if(N == 3){
        cout << "2 5 63" << endl;
        return 0;
    }
    vector<int> S;
    S.push_back(2);
    S.push_back(3);
    S.push_back(4);
    N -= 3;

    vector<int> A0, A2, A3, A4;
    for(int i=6; i<=30000; i+=6) A0.push_back(i);
    for(int i=8; i<=30000; i+=6) A2.push_back(i);
    for(int i=9; i<=30000; i+=6) A3.push_back(i);
    for(int i=10; i<=30000; i+=6) A4.push_back(i);

    //int a = A0.size();
    int b = A2.size();
    int c = A3.size();
    int d = A4.size();

    int z = min(oddnize(N), oddnize(c));
    N -= z;
    int yw = min(min(b, d), N/2);
    N -= 2*yw;
    int x = N;

    REP(i, x) S.push_back(A0[i]);
    REP(i, yw){
        S.push_back(A2[i]);
        S.push_back(A4[i]);
    }
    REP(i, z) S.push_back(A3[i]);

    for(auto x : S)
        cout << x << " ";
    cout << endl;

//    int sm = 0;
//    for(int x : S) sm += x;
//    for(int x : S)
//        assert(__gcd(sm, x) > 1);
//
//    int g0 = __gcd(S[0], S[1]);
//    for(int i=2; i<N; i++)
//        g0 = __gcd(g0, S[i]);
//    assert(g0 == 1);


    return 0;
}
