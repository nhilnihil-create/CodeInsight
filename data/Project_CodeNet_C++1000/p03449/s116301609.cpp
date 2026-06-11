#include <bits/stdc++.h>
#include <vector>
#include <queue>
using namespace std;

int main(){
    int N;
    cin >> N;
    vector<int> A1(N,0);
    vector<int> A2(N,0);

    for(int i=0; i<N; i++){
        cin >> A1[i];
    }
    for(int i=0; i<N; i++){
        cin >> A2[i];
    }

    vector<int> count(N,0);

    for(int i=0; i<N; i++){
        int _count = 0;
        
        for(int j=0; j<=i; j++){
            _count += A1[j];
        }

        for(int k=i; k<N; k++){
            _count += A2[k];
        }

        count[i] = _count;
    }

    int ans = *max_element(count.begin(), count.end());
    cout << ans << endl;
    return 0;
}