#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

int N, ans;
int A[202020];
vector<pii> S;

bool f(int k){
    S.clear();
    for (int i=2; i<=N; i++){
        if (A[i-1] < A[i]) continue;
        if (k <= 1) return false;
        while (!S.empty() && S.back().first > A[i]) S.pop_back();
        for (int j=A[i]; ; j--){
            if (j <= 0) return false;
            if (S.empty()){
                S.push_back(pii(j, 2));
                break;
            }
            pii t = S.back();
            S.pop_back();
            if (t.first == j){
                if (t.second >= k) continue;
                t.second++;
                S.push_back(t);
            }
            else {
                S.push_back(t);
                S.push_back(pii(j, 2));
            }
            break;
        }
    }
    return true;
}

int main(){
    int L, H;
    scanf("%d", &N);
    for (int i=1; i<=N; i++) scanf("%d", &A[i]);
    for (L=1, H=N; L<=H; ){
        int mid = (L+H)/2;
        if (f(mid)) ans = mid, H = mid-1;
        else L = mid+1;
    }
    printf("%d\n", ans);
    return 0;
}

