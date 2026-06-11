#include<bits/stdc++.h>
using namespace std;

const int zero = 8010;

string S;
int X, Y, D;
vector<int> V, H, T;

vector<vector<int> > cc;
int dp(int idx, int x) {
    if(idx == T.size()) return x == zero + D;
    int &ret = cc[idx][x];
    if(ret != -1) return ret;

    ret = 0;
    ret |= dp(idx + 1, x + T[idx]);
    ret |= dp(idx + 1, x - T[idx]);
    return ret;
}

bool solve(int x) {
    D = x;
    cc = vector<vector<int> >(T.size(), vector<int>(2*zero, -1));
    return dp(0, zero);
}

int main() {
    cin >> S >> X >> Y;

    bool isV = true;
    int sum = 0;
    for(int i = 0; i < S.size(); i++) {
        if(S[i] == 'T') {
            if(isV) V.push_back(sum);
            else H.push_back(sum);

            sum = 0;
            isV ^= 1;
        }
        else sum++;
    }
    if(isV) V.push_back(sum);
    else H.push_back(sum);

    X -= V[0];
    for(int i = 1; i < V.size(); i++) T.push_back(V[i]);
    if(!solve(X)) {
        printf("No");
        return 0;
    }

    T.clear();
    for(int i = 0; i < H.size(); i++) T.push_back(H[i]);
    if(!solve(Y)) {
        printf("No");
        return 0;
    }

    printf("Yes");
}
