#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
    int N, Y; cin >> N >> Y;
    for(int i = 0;i <= Y/10000; i++){
        for(int j = 0; j <= (Y-i*10000)/5000; j++){
            int tmp = i * 10000 + j * 5000;
            int tmp2 = (Y - tmp) / 1000;
            if(tmp2+i+j == N){
                cout << i << " " << j << " " << tmp2 << endl;
                return 0;
            }
        }
    }
    cout << -1 << " " << -1 << " " << -1 << endl;
    return 0;
}
