#include <bits/stdc++.h>
using namespace std;

template<typename T>
vector<T> compress(vector<T> A){
    sort(A.begin(), A.end());
    A.erase(unique(A.begin(), A.end()), A.end());
    return A;
}

int main(){
    int N, K, Q;
    cin >> N >> K >> Q;
    vector<int> A(N);
    for(int i=0; i<N; i++) cin >> A[i];
    auto cmp = compress(A);

    int ans = 1e9;
    for(int mn : cmp){
        vector<int> avail;
        vector<int> len;
        for(int i=0; i<=N; i++){
            if(i<N && mn <= A[i]){
                len.push_back(A[i]);
            }else{
                sort(len.begin(), len.end());
                int sz = len.size();
                for(int j=0; j<sz-K+1; j++) avail.push_back(len[j]);
                len.clear();
            }
        }
        sort(avail.begin(), avail.end());
        if(avail.size() >= Q) ans = min(ans, avail[Q-1] - mn);
    }
    cout << ans << endl;
}