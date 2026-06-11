#include<iostream>
#include<iomanip>
#include<cstdio>

#include<vector>
#include<queue>
#include<set>
#include<map>
#include<string>

#include<algorithm>
#include<cmath>
#include<numeric>

using namespace std;
typedef long long ll;
template <class T> inline bool chmax(T& a, T b) {if (a < b) {a = b; return 1;} return 0;}
template <class T> inline bool chmin(T& a, T b) {if (a > b) {a = b; return 1;} return 0;}
const ll INF = 1e18+1;

/*
区間の長さKについて二分探索が可能
∵Kが小さくても大きい時の操作は全く同じように実行可能だから


全て0にできるかどうかは、どうやって判定できるのか???

1ならもちろんおけ

1の連結区間の最小長さはもちろんおけ
だってそれ以上の長さの区間は任意に反転できるから

1の連結区間の最小長さkとして、左右からk+1地点よりも外側は任意に
1マスずつ反転可能

xに対し
左右からx地点よりも内側が0足りうる最大x
*/

/*
bool f(int K, string S) {
    int N = S.length();
    for (int i = N-K; i < K; i++) {
        if (S[i] == '1') return false;
    }
    return true;
}*/
/*
int main() {
    string S; cin >> S;

    int l = (S.length()+1)/2, r = S.length();

    while (r - l > 1) {
        int mid = (r+l)/2;
        if (f(mid,S)) l = mid;
        else r = mid;
    }
    cout << l << endl;
}*/

int main() {
    string S; cin >> S;

    int N = S.length(); 
    int res = N;

    for (int i = 0; i <= N / 2; i++) {
        if (S[i] != S[i+1] || S[N-i-1] != S[N-i-2]) {
            chmin(res, max(i+1,N-i-1));
        }
    }
    cout << res << endl;
}
