#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr int Inf = 1000000000;
constexpr ll INF= 1e18;
constexpr ll MOD = 1000000007;
const double PI = 3.1415926535897;
typedef pair<int,int> P;

int main() {
    int N,A,B,C,D;
    cin >> N >> A >> B >> C >> D;
    A--;
    B--;
    C--;
    D--;
    string S;
    cin >> S;
    S += '#';
    if(C < D) {
        bool ret = true;
        for(int i = A;i <= C;i++) {
            if(S.at(i) == '#' && S.at(i + 1) == '#') {
                ret = false;
            }
        }
        for(int i = B;i <= D;i++) {
            if(S.at(i) == '#' && S.at(i + 1) == '#') {
                ret = false;
            }
        }
        if(ret == true) {
            cout << "Yes" << endl;
        }
        else {
            cout << "No" << endl;
        }
    }
    else {
        bool ret = true;
        for(int i = A;i <= C;i++) {
            if(S.at(i) == '#' && S.at(i + 1) == '#') {
                ret = false;
            }
        }
        for(int i = B;i <= D;i++) {
            if(S.at(i) == '#' && S.at(i + 1) == '#') {
                ret = false;
            }
        }
        bool ret2 = false;
        for(int i = B;i <= D;i++) {
            if(S.at(i - 1) == '.' && S.at(i) == '.' && S.at(i + 1) == '.') {
                ret2 = true;
            }
        }
        if(ret == true && ret2 == true) {
            cout << "Yes" << endl;
        }
        else {
            cout << "No" << endl;
        }
    }
}