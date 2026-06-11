#include <bits/stdc++.h>
#include <vector>
#include <queue>
using namespace std;

int main(){
    int N;
    cin >> N;
    vector<long long> a(N,0);
    for(int i=0; i<N; i++){
        cin >> a[i];
    }

    long long a_max = *max_element(a.begin(), a.end());
    long long ans = 0;
    
    for(int i=0;i<N;i++){
        ans += a[i] - 1;
    }

    cout << ans << endl;
    return 0;
}