/**
*    author:  Taichicchi
*    created: 10.09.2020 20:27:09
**/

#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

int main() {

    int N, M, C;

    cin >> N >> M >> C;

    vector<int> B(M);

    for(int i=0;i<M;++i) {
        cin >> B[i];
    }

    ll cnt = 0;

    int a;

    vector<int> A(M);
    for( int i = 0 ; i < N ; ++i ) {
        A.clear();
        ll q = 0;
        for(int j = 0; j < M ; ++j ) {
            cin >> a;
            q += a * B[j];
        }
        q += C;
        if(q > 0){
            cnt += 1;
        }
    }

    cout << cnt << endl;

    return 0;
}