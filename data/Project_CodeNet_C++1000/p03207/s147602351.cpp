#include<bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;
    vector<int>P(N);
    int cnt = 0;
    int X = 0;
    for(int i = 0; i < N; i++) {
        cin >> P[i];
        cnt += P[i];
        X = max(X,P[i]);
    }
    cout << cnt-X/2 << endl;
}
