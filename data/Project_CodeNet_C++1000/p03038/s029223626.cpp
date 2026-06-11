#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int64_t N,M,A,B,C;
    int64_t remains;
    int64_t sum;

    cin >> N >> M;

    map<int64_t,int64_t,greater<int64_t>> mp;
    for(int64_t i=0;i<N;i++) {
        cin >> A;
        mp[A]++;
    }

    for(int64_t i=0;i<M;i++) {
        cin >> B >> C;
        mp[C] += B;
    }

    remains = N;
    sum = 0;
    for(map<int64_t,int64_t,greater<int64_t>>::iterator it=mp.begin();it!= mp.end();it++)  {
        if(remains > it->second) {
            sum += (it->first * it->second);
            remains -= it->second;
        } else {
            sum += (it->first * remains);
            break;
        }
    }
    
    cout << sum << endl;
    
    return 0;
}