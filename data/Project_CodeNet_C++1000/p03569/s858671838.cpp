#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll ZERO = 0;
const int Inf = 1e9;
const ll INF= 1e18;
const ll MOD = 1000000007;
const double PI = 3.1415926535897;
typedef pair<int,int> P;

int main() {
    string S;
    cin >> S;
    string T;
    vector<int> vec;
    int cnt = 0;
    for(int i = 0;i < S.size();i++) {
        if(S.at(i) != 'x') {
            T.push_back(S.at(i));
            vec.push_back(cnt);
            cnt = 0;
        }
        else {
            cnt++;
        }
    }
    vec.push_back(cnt);
    bool ret1 = true;
    for(int i = 0;i < T.size();i++) {
        if(T.at(i) != T.at(T.size() - 1 - i)) {
            ret1 = false;
        }
    }
    if(ret1 == false) {
        cout << -1 << endl;
    }
    else {
        int ret2 = 0;
        for(int i = 0;i < vec.size() / 2;i++) {
            ret2 += max(vec.at(i),vec.at(vec.size() - 1 - i)) - min(vec.at(i),vec.at(vec.size() - 1 - i));
        }
        cout << ret2 << endl;
    }
}