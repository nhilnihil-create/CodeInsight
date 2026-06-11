#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (int i = 0; i< (n); ++i)
const long long INF = 1LL<<58;

// aを常に小さい値にする
template<class T> void chmin(T &a, T b){ if(a>b) a = b; }

// 二分探索 前方のindexを返すもの（自分自身を含む） 前方: -INF側のこと
template<class T> int former(const vector<T> &v, T x){
    return upper_bound(v.begin(), v.end(), x) - v.begin() -1; // upper_bound : keyより大きい要素の内の一番左側のイテレータを返す
}
// 二分探索 後方のindexを返すもの（自分自身を含む）後方: INF側のこと
template<class T> int latter(const vector<T> &v, T x){
    return lower_bound(v.begin(), v.end(), x) - v.begin(); // lower_bound : key以上の要素の内の一番左側のイテレータを返す
}

/*
 * */
int main() {
    char b;
    cin >> b;

    map<char,char> change;
    change['A'] = 'T';
    change['T'] = 'A';
    change['C'] = 'G';
    change['G'] = 'C';
    
    cout << change[b] << endl;
}