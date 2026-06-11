#include <bits/stdc++.h>
using namespace std;

int main(){
    int N,M,C;
    cin >> N >> M >> C;
    
    vector<int> b(M);
    for(int i = 0; i < M; i++){
        cin >> b[i];
    }
    int res = 0;
    for(int i = 0; i < N; i++){
        int what = C;
        int a;
        for(int j = 0; j < M; j++){
            cin >> a;
            what += a*b[j];
        }
        if(what > 0){
            res += 1;
        }
    }
    
    cout << res << endl;
    
    return 0;
}