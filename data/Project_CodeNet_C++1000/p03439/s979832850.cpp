#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

// static const int MAX = 1e6;
// static const int NIL = -1;
// static const ll INF = 1<<21;
// static const ll MOD = 1e9 + 7;

bool compPair(const pair<int, int>& arg1, const pair<int, int>& arg2) {
    return arg1.first > arg2.first;
}

map<int, int> numsex;
string ss;

void query(int n) {
    cout << n << endl; cout.flush();
    cin >> ss;
    if(ss=="Male") {
        numsex.insert(make_pair(n, 1));
    }
    else if(ss=="Female") {
        numsex.insert(make_pair(n, -1));
    }
    else exit(0);
}

int main(void) {
    int n;
    cin >> n;

    query(0);
    query(n-1);

    int l=0, m, r=n-1;
    for(int i=2;i<20;i++) {
        m = (l+r)/2;
        query(m);

        if((m-l)%2==1&&numsex[l]==numsex[m]) {
            r = m;
        }
        else if((m-l)%2==0&&numsex[l]!=numsex[m]) {
            r = m;
        }
        else if((r-m)%2==1&&numsex[m]==numsex[r]) {
            l = m;
        }
        else {
            l = m;
        }
    }

    return 0;
}
