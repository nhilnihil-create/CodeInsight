#include "bits/stdc++.h"
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const long long MOD = 1e9 + 7, MAX = 1e18, larg = 1e5, INF = -1e9;
long long A, B, C, D, E, F, G, H, I, J, K, L, N, M, O, P, Q, R, S, T, U, V, W;
typedef long long ll;
typedef pair<ll, ll> Pa;

priority_queue<Pa> que;

int main()
{
    cin >> N >> H;
    rep(i, N){
        cin >> A >> B;
        que.push(Pa(A, 0));
        que.push(Pa(B, 1));
    }
    ll point = 0;
    int index = 0;
    while(point < H){
        Pa curr = que.top(); 
        if(curr.second == 0){
            index += (H - point-1)/curr.first+1;
            point = H;
        }else{
            que.pop();
            point += curr.first;
            index++;
        }
    }
    cout << index;
}
