#include <bits/stdc++.h>
using namespace std;

const int K = 10000;
bool XC[3*K], YC[3*K], XCN[3*K], YCN[3*K];

int main() {
    string S; int N, X, Y;
    cin >> S >> X >> Y;
    N = S.size();

    bool mode = 0;
    vector<int> xs, ys;
    int x = N, cnt = 0;
    for(int i=0; i<N; i++) {
        if(S[i] == 'T') {x = i; break;}
        ++cnt;
    }
    XC[cnt + K] = YC[K] = 1;
    for(int i=x, c=0; i<N; i++) {
        if(S[i] == 'T') {
            if(c) {
                if(mode) ys.push_back(c);
                else xs.push_back(c);
                c = 0;
            }
            mode = !mode;
        }
        else {
            ++c;
            if(i == N-1 && c) {
                if(mode) ys.push_back(c);
                else xs.push_back(c);
            }
        }
    }
    for(auto& it: xs) {
        for(int i=-8000; i<=8000; i++) if(XC[i + K]) XCN[i - it + K] = XCN[i + it + K] = 1;
        for(int i=-8000; i<=8000; i++) XC[i + K] = XCN[i + K], XCN[i + K] = 0;
    }
    for(auto& it: ys) {
        for(int i=-8000; i<=8000; i++) if(YC[i + K]) YCN[i - it + K] = YCN[i + it + K] = 1;
        for(int i=-8000; i<=8000; i++) YC[i + K] = YCN[i + K], YCN[i + K] = 0;
    }
    if(XC[X + K] && YC[Y + K]) puts("Yes");
    else puts("No");
    return 0;
}
