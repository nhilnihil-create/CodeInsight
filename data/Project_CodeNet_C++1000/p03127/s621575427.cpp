#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int64_t N;
    int64_t mina;
    int mincnt;
    cin >> N;

    vector<int64_t> A(N);
    for(int i=0;i<N;i++) {
        cin >> A[i];    
    }

    mina = *min_element(A.begin(), A.end());
    mincnt = 0;
    map<int,int> mpa;
    map<int,int> mpb;
    map<int,int>* cur;
    map<int,int>* tgt;
    map<int,int>* tmp;
    for(int i=0;i<N;i++) {
        if(mina == A[i]) {
            mpa[mina]++;
        } else {
            if(A[i]%mina == 0) continue;
            mpa[A[i]%mina]++;
        }
    }
        
    tgt = &mpa;
    cur = &mpb;
    while(tgt->size() > 1){
        mina = tgt->begin()->first;
        for(auto m: (*tgt)) {
            if(mina == m.first) {
                (*cur)[mina]++;
            } else {
                if(m.first % mina == 0) continue;
                (*cur)[m.first%mina]++;
            }
        }
        
        tmp = tgt;
        tgt = cur;
        cur = tmp;
        cur->clear();
    }

    cout << tgt->begin()->first << endl;
    return 0;
}
