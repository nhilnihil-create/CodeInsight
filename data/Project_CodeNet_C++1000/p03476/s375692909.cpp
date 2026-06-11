#include<bits/stdc++.h>

using namespace std;

int main(){
    int N = (int)(1e5 + 0.5);
    // エラトステネスの篩
    vector<bool> isPrime(N, true);
    isPrime.at(0) = isPrime.at(1) = false;
    for(int i=2; i<N; i++){
        if(!isPrime.at(i))continue;
        for(int j = i*2; j<N; j+=i)isPrime.at(j) = false;
    }

    // 2017-like数か否か
    vector<bool> is2017like(N, false);
    for(int i=0; i<N; i++){
        if(i % 2 == 0)continue;
        if(isPrime.at(i) && isPrime.at((i+1)/2))is2017like.at(i) = true;
    }

    // is2017likeの累積和
    vector<int> cs(N+1, 0);
    for(int i=0; i<N; i++)cs.at(i+1) = cs.at(i) + is2017like.at(i);

    int Q;
    cin >> Q;
    for(int i=0; i<Q; i++){
        int l,r;
        cin >> l >> r;
        cout << cs.at(r+1) - cs.at(l) << endl;
    }
}