#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int N;

int main(void){
    
    cin >> N;
    
    vector<int> L(N + 1);
    vector<int> R(N + 1);
    for(int i = 0; i < N; ++i) cin >> L[i] >> R[i];
    
    sort(L.begin(), L.end());
    sort(R.begin(), R.end(), greater<int>());
    
    ll result = 0;
    for(int i = 0; i <= N; ++i){
        if(L[i] > R[i]) result += 2 * (L[i] - R[i]);
    }
    
    cout << result << endl;
    
    return 0;
}
