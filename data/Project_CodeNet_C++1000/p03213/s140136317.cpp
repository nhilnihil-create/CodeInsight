#include <iostream>
#include <algorithm>
#include <cmath>
#include <map>

using namespace std;

void factorize(long N, map<long, long> *m){
    long lim = sqrt(N);
    long div = 2;
    while(N != 1 && div <= lim){
        long cnt = 0;
        while(N % div == 0){
            cnt ++;
            N /= div;
        }
        if(cnt != 0) (*m).insert({div, cnt});
        div ++;
    }
    if(N != 1) (*m).insert({N, 1});
}

int main(){

    int N;
    cin >> N;

    long cnt[N + 1]; fill(cnt, cnt + N + 1, 0);
    for(int i=1; i<=N; i++){
        map<long, long> m;
        factorize(i, &m);
        for(auto itr = m.begin(); itr != m.end(); ++itr){
            cnt[itr->first] += itr->second;
        }    
    }
    long n74, n24, n14, n4, n2; 
    n74 = n24 = n14 = n4 = n2 = 0;
    for(int i=2; i<=N; i++){
        if(cnt[i] >= 74) n74++;
        if(cnt[i] >= 24) n24++;
        if(cnt[i] >= 14) n14++;
        if(cnt[i] >= 4) n4++;
        if(cnt[i] >= 2) n2++;
    }
    cout << n74 + n24 * (n2 - 1) + n14 * (n4 - 1) + n4 * (n4-1) / 2 * (n2 - 2) << endl;
    return 0;
}