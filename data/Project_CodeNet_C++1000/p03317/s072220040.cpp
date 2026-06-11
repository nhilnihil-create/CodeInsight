#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    vector<int> vec(N);
    int mi = 1;
    for(int i=0; i<N; i++){
        cin >> vec[i];
        if(vec[i]==1){
            mi = i;
        }
    }

    int ans= 214700000;
    for(int i=0; i<K; i++){
        int count=1;
        int migi = mi +K-1 -i;
        while(migi<N-1){
            migi += K-1;
            count++;
        }
        int hidari=mi -i;
        while(hidari>0){
            hidari -= K-1;
            count++;
        }
        ans = min(ans, count);
    }
    cout << ans << endl;
}
