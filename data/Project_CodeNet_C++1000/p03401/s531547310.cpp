#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)

int main() {
    int N,s=0,t;
    cin >> N;
    vector<int> A(N+2);

    A.at(0)=0, A.at(N+1)=0;
    rep(i,N) {
        cin >> A.at(i+1);
        s += abs(A.at(i+1)-A.at(i));
    }
    s += abs(A.at(N+1)-A.at(N));

    rep(i,N) {
        t = abs(A.at(i+1)-A.at(i))+abs(A.at(i+2)-A.at(i+1))-abs(A.at(i+2)-A.at(i));
        cout << s-t << endl;
    }
}