#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int> P;
int INF = 1e18;
int mod = 1e9+7;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
signed main() {
    int N,K;
    cin >> N >> K;
    vector<string>A(N);
    for(int i = 0; i < N; i++) {
        int a;
        cin >> a;
        string S = "";
        for(int i = 0; i < 45; i++) {
            S += to_string(a%2);
            a/=2;
        }
        reverse(S.begin(),S.end());
        A[i] = S;
    }
    string S = "";
    for(int i = 0; i < 45; i++) {
        S += to_string(K%2);
        K/=2;
    }
    reverse(S.begin(),S.end());
    bool ok = false,ok2 = false;
    int cnt1 = 0;
    int cnt2 = 0;
    for(int i = 0; i < 45; i++) {
        int X = 0,Y = 0;
        for(int j = 0; j < N; j++) {
            if(A[j][i] == '1') {
                X++;
            }
            else {
                Y++;
            }
        }
        if(X >= Y) {
            cnt1 += (int)pow((double)2,(double)44-i)*X;
            cnt2 += (int)pow((double)2,(double)44-i)*X;
            if(S[i] == '1') {
                ok2 = true;
            }
        }
        else {
            if(ok) {
                cnt2 += (int)pow((double)2,(double)44-i)*Y;
                if(S[i] == '1' || ok2) {
                    cnt1 += (int)pow((double)2,(double)44-i)*Y;
                }
                else {
                    cnt1 += (int)pow((double)2,(double)44-i)*X;
                }
            }
            else {
                cnt2 += (int)pow((double)2,(double)44-i)*X;
                if(S[i] == '1' || ok2) {
                    cnt1 += (int)pow((double)2,(double)44-i)*Y;
                }
                else {
                    cnt1 += (int)pow((double)2,(double)44-i)*X;
                }
            }
        }
        if(S[i] == '1') {
            ok = true;
        }
    }
    cout << max(cnt1,cnt2) << endl;
}
