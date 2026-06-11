/**
SXR0aXAkI0JwbXptI3FhI3Z3I293bCNqY2IjUG0jMCNicG0jVHFkcXZvLyNCcG0jQW10bjBhY2phcWFicXZvLyNNYm16dml0MSNWdyNhdGN1am16I2tpdiNhbXF9bSNQcXUjVnd6I0F0bW14MSNQcWEjaXptI2l0dCNicHF2b2EjUXYjYnBtI3BtaWRtdmEjaXZsI3d2I21pemJwMSNFcHcjcWEjYnBtem0ja2l2I3F2Ym16a21sbSNRdiNQcWEjeHptYW12a20jbXtrbXhiI0lhI3BtI3htenVxYmJtYnBHI1BtI3N2d2VtYnAjRXBpYiMraXh4bWl6bWJwI2J3I1BxYSNrem1pYmN6bWEjSWEsI0ptbnd6bSN3eiNJbmJteiN3eiNKbXBxdmwjYnBtdTEjVnd6I2FwaXR0I2JwbXwja3d1eGlhYSNJY29wYiN3biNwcWEjc3Z3ZXRtbG9tI017a214YiNpYSNQbSNlcXR0bWJwMSNQcWEjYnB6d3ZtI2x3YnAjbXtibXZsI1dkbXojYnBtI3BtaWRtdmEjSXZsI3d2I21pemJwLyNpdmwjUG0jbm1tdG1icCNWdyNuaWJxb2NtI3F2I29jaXpscXZvI0l2bCN4em1hbXpkcXZvI2JwbXUvI053eiNQbSNxYSNicG0jVXdhYiNQcW9wMSNCcG0jQWN4em11bSMrcXYjb3R3enwsMQ==
*/
#include <cstring>
#include <vector>
#include <complex>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <queue>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cassert>
 
#define F first
#define S second
#define endl '\n'
#define deb(x) cout<<#x<<' '<<x<<endl;
#define pb push_back
#define ll long long
 
const long long MAXN = 1e7 + 1;
const long long MOD = 1e9 + 7;
using namespace std;
 
typedef pair<int, int> pii;
 
 
long long readInt() {
    bool minus1 = false;
    long long result = 0;
    char ch;
    ch = getchar();
    while (true) {
        if (ch == '-') break;
        if (ch >= '0' && ch <= '9') break;
        ch = getchar();
    }
    if (ch == '-') minus1 = true; else result = ch-'0';
    while (true) {
        ch = getchar();
        if (ch < '0' || ch > '9') break;
        result = result*10 + (ch - '0');
    }
    if (minus1)
        return -result;
    else
        return result;
}

#define int ll

 main(){
	#ifdef IZI_KATKA
	assert(freopen("input", "r", stdin));
    assert(freopen("output", "w", stdout));
    #endif
    int M = readInt(), K = readInt();
    if (K == 0) {
        for (int i = 0; i < (1ll << M); i++) {
            cout << i << ' ' << i << ' ';
        }
        return 0;
    }
    if (K > (1ll << M)) {
        cout << -1;
        return 0;
    }
    int res = 0;
    for (int i = 0; i < (1 << M); i++) {
        if (i == K) continue; 
        res ^= i;
    }
    if (res != K) {
        cout << -1;
        return 0;
    }
    for (int i = 0; i < (1 << M); i++) {
        if (i == K) continue;
        cout << i << ' ';
    }
    cout << K << ' ';
    for (int i = (1 << M) - 1; i >= 0; i--) {
        if (i == K) continue;
        cout << i << ' ';
    }
    cout << K;
    return 0;
}
