#include <bits/stdc++.h>
using namespace std;

int main(){
    
    int ans = 1145141919;
    int N, K, Q;
    cin >> N >> K >> Q;
    vector<int>A(N + 1, 0);
    for(int i=0; i<N; i++)cin >> A[i];
    for(int i=0; i<N; i++){
        vector<int>tmp, tmp2;
        for(int j=0; j<=N;j++){
            if(A[j] < A[i]){
                if(tmp2.size() >= K){
                    sort(tmp2.begin(), tmp2.end());
                    for(int k=0; k+K-1<tmp2.size(); k++){
                        tmp.push_back(tmp2[k]);
                    }
                }
                tmp2.clear();
            }
            else tmp2.push_back(A[j]);
        }
        if(tmp.size()<Q)continue;
        sort(tmp.begin(), tmp.end());
        ans = min(ans, abs(tmp[Q-1] - tmp[0]));
    }
    cout << ans << endl;
    return 0;
}
