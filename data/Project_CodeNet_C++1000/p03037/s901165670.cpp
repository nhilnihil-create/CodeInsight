#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int N, M;
    cin >> N >> M;

    int R[M];
    int L[M];
    for(int i=0; i<M; i++){
        cin >> L[i] >> R[i];
    }

    int min_R = *max_element(L, L+M);
    int max_R = *min_element(R, R+M);

    int count = max_R - min_R + 1;
    if(count < 0){
        count = 0;
    }

    cout << count << endl;
    return 0;
    
}