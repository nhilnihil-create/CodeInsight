#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
// 22:22
// static const int MAX = 1e6;
// static const int NIL = -1;
// static const ll INF = 1<<21;
// static const ll MOD = 1e9 + 7;

// bool compPair(const pair<int, int>& arg1, const pair<int, int>& arg2) {
//     return arg1.first > arg2.first;
// }

// template<class T> void chmin(T& a, T b) {
//     if (a > b) {
//         a = b;
//     }
// }

// template<class T> void chmax(T& a, T b) {
//     if (a < b) {
//         a = b;
//     }
// }

int main(void) {
    int n;
    cin >> n;

    vector <int> p(n+1);
    int tmp, cnt;
    for(int in=1;in<=n;in++) {
        tmp = in;
        for(int j=2;j*j<=tmp;j++) {
            cnt = 0;
            while(tmp%j==0) {
                tmp /= j;
                cnt++;
            }
            p.at(j) += cnt;
        }
        if(tmp>1) {
            p.at(tmp) += 1;
        }
    }

    int count74=0, count24=0, count14=0, count4=0, count2=0;
    for(auto ip:p) {
        if(ip>=74) count74++;
        if(ip>=24) count24++;
        if(ip>=14) count14++;
        if(ip>=4) count4++;
        if(ip>=2) count2++;
    }

    cout << count74 + count24*(count2-1) + count14*(count4-1) + (count4)*(count4-1)*(count2-2)/2 << endl;

    // for(auto ip:p) {
    //     cout << ip << endl;
    // }

    return 0;
}
