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
        if(a==b && b==c);
        else if(a==b||b==c||c==a)cnt++;
        else {cnt++;cnt++;}
    }
    cout << cnt << endl;
}   