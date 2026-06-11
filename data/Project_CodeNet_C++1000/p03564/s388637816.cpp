#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (int)(n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main(){
    int N, K, n = 1;
    cin >> N;
    cin >> K;

    rep(i, N)
    {
        if(n <= K){
            n *= 2;
        }else{
            n += K;
        }
    }
    cout << n << endl;
    return 0;
}