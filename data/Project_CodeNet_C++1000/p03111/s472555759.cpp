#include <bits/stdc++.h>
using namespace std;

typedef long lint;
typedef long long llint;
typedef pair<int, int> pint;
typedef pair<long long, long long> pllint;
typedef tuple<long long, long long, long long> tllint;

// static const int MAX = 1e6;
// static const int NIL = -1;
// static const llint INF = 1<<21;
// static const llint MOD = 1e9 + 7;

bool compPair(const pint& arg1, const pint& arg2) { return arg1.first > arg2.first; }
bool compTuple(const tllint& arg1, const tllint& arg2) { return get<2>(arg1) > get<2>(arg2); }
template<class T> void chmax(T& a, T b) { if (a < b) { a = b; } }
template<class T> void chmin(T& a, T b) { if (a > b) { a = b; } }

int main(void) {
    int n, a, b, c;
    cin >> n >> a >> b >> c;

    vector<int> l(n);
    int upper = 1;
    for(int in=0;in<n;++in) {
        cin >> l[in];
        upper *= 4;
    }

    bool flga, flgb, flgc;
    int braa, brab, brac, allbra, onebra;
    int ans = 10000, anstmp;
    for(int iu=0;iu<upper;++iu) {
        flga = false;
        flgb = false;
        flgc = false;
        braa = 0;
        brab = 0;
        brac = 0;
        anstmp = 0;
        allbra = iu;
        for(int in=0;in<n;++in) {
            onebra = allbra % 4;
            if(onebra==1) { 
                braa += l[in];
                if(flga) anstmp += 10;
                flga = true;
            }
            else if(onebra==2) { 
                brab += l[in];
                if(flgb) anstmp += 10;
                flgb = true;
            }
            else if(onebra==3) { 
                brac += l[in];
                if(flgc) anstmp += 10;
                flgc = true;
            }
            else ;
            allbra /= 4;
        }
        anstmp += abs(braa-a);
        anstmp += abs(brab-b);
        anstmp += abs(brac-c);
        if(flga&flgb&flgc) chmin(ans, anstmp);
    }

    cout << ans << endl;
    return 0;
}
