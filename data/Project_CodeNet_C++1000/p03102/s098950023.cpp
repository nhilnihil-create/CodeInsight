#include <bits/stdc++.h>
using namespace std;

int main(){
    int N, M, C;
    vector<int> Bs(21);
    int A;

    cin >> N >> M >> C;

    for(int i = 0; i < M; i++){
        cin >> Bs[i];
    }

    int cnt = 0;
    for(int i = 0; i < N; i++){
        int feature = C;
        for(int j = 0; j < M; j++){
            cin >> A;
            feature += A * Bs[j];
        }
        if(feature > 0){
            cnt += 1;
        }
    }
    cout << cnt << endl;

    return 0;
}