#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;


int main() {
    int N; cin >> N;
    int cnt = 0;
    int check[60000];
    rep(i, 60000){
        check[i] = 1;
    }
    for (int i = 2; i < 60000; i++){
        if(check[i] == 1){
            for (int j = i+i; j < 60000; j+=i){
                check[j] = 0;
            }
            if(i % 5 == 1){
                cout << i << endl;
                cnt++;
                if(cnt == N){
                    return 0;
                }
            }
        }
    }

    return 0;
}