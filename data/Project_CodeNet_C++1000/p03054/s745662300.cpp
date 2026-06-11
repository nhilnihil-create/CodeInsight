#include <bits/stdc++.h>

#define rep(i, n) for(int i = 0; i < n; i++)

using namespace std;
using ll = long long;
int mod = 1000000007;

void solve();

int main(void){
    int H, W, N; cin >> H >> W >> N;
    int sx, sy; cin >> sx >> sy;
    string S, T; cin >> S >> T;

    vector<int> U(N, 0), D(N, 0), R(N, 0), L(N, 0);
    rep(i, N){
        if(i == 0){
            if(S[0] == 'U') U[0]++;
            else if(S[0] == 'D') D[0]++;
            else if(S[0] == 'R') R[0]++;
            else L[0]++;
            continue;
        }
        switch(S[i]){
            case 'R':
                R[i] = R[i-1]+1;
                L[i] = L[i-1];
                U[i] = U[i-1];
                D[i] = D[i-1];
                break;
            case 'L':
                R[i] = R[i-1];
                L[i] = L[i-1]+1;
                U[i] = U[i-1];
                D[i] = D[i-1];
                break;
            case 'U':
                R[i] = R[i-1];
                L[i] = L[i-1];
                U[i] = U[i-1]+1;
                D[i] = D[i-1];
                break;
            case 'D':
                R[i] = R[i-1];
                L[i] = L[i-1];
                U[i] = U[i-1];
                D[i] = D[i-1]+1;
                break;
            default:
                break;
        }
    }

    vector<pair<int, int>> tate(N+1);
    vector<pair<int, int>> yoko(N+1);
    tate[0] = make_pair(sx, sx);
    yoko[0] = make_pair(sy, sy);
    rep(i, N){
        switch(T[i]){
            case 'R':
                tate[i+1] = tate[i];
                yoko[i+1] = make_pair(yoko[i].first, min(W+L[i], yoko[i].second+1));
                break;
            case 'L':
                tate[i+1] = tate[i];
                yoko[i+1] = make_pair(max(1-R[i], yoko[i].first-1), yoko[i].second);
                break;
            case 'U':
                tate[i+1] = make_pair(max(1-D[i], tate[i].first-1), tate[i].second);
                yoko[i+1] = yoko[i];
                break;
            case 'D':
                tate[i+1] = make_pair(tate[i].first, min(H+U[i], tate[i].second+1));
                yoko[i+1] = yoko[i];
                break;
            default:
                break;
        }
    }
    //iターン後に終了するには、任意のtate[i].first以上tate[i].second以下の数について
        //または任意のyoko[i].first以上yoko[i].second以下の数について
        //外に出れるか判定する必要がある
        //縦方向で考えると
        //iターン目までにUがK回 -> 押し出せるのはK以下の区間
        //iターン目までにDがL回 -> 押し出せるのは(H+1)-L以上の区間
        //これら二つの区間によってtate[i]がカバーされるなら取り除ける
        //カバーされるとき: 2つの区間に重なりがあるまたは片方の区間がtate[i]の全てをカバーするとき
    rep(i, N){
        //U[i]以下または(H+1)-D[i]以上の区間内に入っているなら取り除ける
        //cout << "tate: " << tate[i].first << " " << tate[i].second << endl;
        //cout << "yoko: " << yoko[i].first << " " << yoko[i].second << endl;
        if(tate[i].second <= U[i] || (H+1)-D[i] <= tate[i].first
        || yoko[i].second <= L[i] || (W+1)-R[i] <= yoko[i].first){
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    return 0;
}

void solve(){}