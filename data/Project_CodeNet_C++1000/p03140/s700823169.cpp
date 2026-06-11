#include "bits/stdc++.h"
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)


int main(){
    int N;
    string A,B,C;
    cin >> N >> A >> B >> C;
    int cnt = 0;
    rep(i,N){
        char a = A.at(i),b = B.at(i), c = C.at(i);
        set<int> S;
        S.insert(a);
        S.insert(b);
        S.insert(c);
        cnt += S.size() -1;
    }
    cout << cnt << endl;
}   