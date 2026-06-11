#define _GLIBCXX_DEBUG

#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (int)(n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main(){
    int N;
    cin >> N;

    ll memo0 = 2;
    ll memo1 = 1;
    ll memo = 1;
    int count = 0;

    if(N < 2){
        cout << 1 << endl;
        return 0;
    }

    while(true){
        count++;
        if(count == N) break;
        memo = memo0 + memo1;
        memo0 = memo1;
        memo1 = memo;
    }

    cout << memo << endl;

    return 0;
}