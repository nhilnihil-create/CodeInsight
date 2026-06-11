#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

vector<vector<int>> bitcnt;
int K;

vector<int> select(vector<int>& origin, int bit){
    if(bit == -1) return origin;
    int cnt = 0;
    vector<int> nextIdx;
    for(int i : origin){
        if(bitcnt[i][bit] == 1){
            nextIdx.push_back(i);
        }
    }

    if(nextIdx.size() < K)
        return select(origin, bit - 1);
    else
        return select(nextIdx, bit - 1);
}

int main(){
    int N;  cin >> N >> K;
    vector<ll> A(N+1, 0), sum(N+1, 0);
    for(int i=1; i<=N; i++){
        cin >> A[i];
        sum[i] += sum[i-1] + A[i];
    }

    vector<ll> B;
    for(int i=1; i<=N; i++) for(int j=i; j<=N; j++){
        B.push_back(sum[j] - sum[i-1]);
    }
    sort(B.begin(), B.end());
    int W = B.size();

    bitcnt.resize(W, vector<int>(61, 0));
    for(int i=0; i<W; i++){
        ll b = B[i];
        for(int k=0; k<61; k++){
            if(b%2==1){
                bitcnt[i][k]++;
            }
            b/=2;
        }
    }
    vector<int> idx(W);
    for(int i=0; i<W; i++)
        idx[i] = i;
    vector<int> selected = select(idx, 60);
    ll ans = -1;
    for(int i : selected){
        if(ans == -1) ans = B[i];
        else ans &= B[i];
    }
    cout << ans << endl;
}