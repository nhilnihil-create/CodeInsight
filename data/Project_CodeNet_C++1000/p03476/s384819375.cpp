#include <bits/stdc++.h>
using namespace std;

#define N 100000

set<int> similarTo2017Number;

void set_similar_to_2017(int n){
    for (int i = 3; i <= n; i=i+2){
        bool isSimilar = true;
        for (int j = 2; j <= sqrt(i); j++){
            if(i % j == 0){
                isSimilar = false;
                break;
            }
            if( ((i+1)/2) % j == 0 ){
                isSimilar = false;
                break;
            } 
        }
        if (isSimilar){
            similarTo2017Number.insert(i);
        }
    }
}

int main() {
    vector<int> nSimilarTo2017(N+1,0);
    set_similar_to_2017(N);
    for (auto itr = similarTo2017Number.begin(); itr != similarTo2017Number.end(); itr++){
        nSimilarTo2017[(*itr)] = 1;
    }
    for (int i = 1; i <= N; i++){
        nSimilarTo2017[i] += nSimilarTo2017[i-1];
    }
    
    // 入力
    int q;
    cin >> q;

    for (int i = 0; i < q; i++){
        int l, r;
        cin >> l >> r;
        cout << nSimilarTo2017[r] - nSimilarTo2017[l-1] << endl;
    }

    return 0;
}
