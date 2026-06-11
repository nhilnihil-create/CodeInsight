#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int N, M;
    cin>> N >> M;

    vector<int> cnt(M+1, 0);
    for(int i=0; i<N; i++){
        int K;
        cin>> K;
        for(int j=0; j<K; j++){
            int A;
            cin>>A;
            cnt[A]++;
        }
    }

    int all_cnt = 0;
    for(int i=1; i<=M; i++){
        if(cnt[i]==N){
            all_cnt++;
        }
    }

    cout<< all_cnt <<endl;
    return 0;
}