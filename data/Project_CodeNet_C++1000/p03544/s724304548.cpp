#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int) (n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int) (n); i++)
#define _GLIBCXX_DEBUG

typedef long long ll;

int main(){
    ll L0 = 2, L1 = 1, LN;
    int N;
    cin >> N;
    if(N == 0){
        cout << L0 << endl;
        return 0;
    }
    if(N == 1){
        cout << L1 << endl;
        return 0;
    }
    N--;
    while(N--){
        LN = L0+L1;
        L0 = L1;
        L1 = LN;
    }
    cout << LN << endl;
}