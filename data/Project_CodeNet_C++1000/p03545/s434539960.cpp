#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;

int main(){
    int N;
    vector<int> n(4);
    cin >> N;
    n.at(0) = N / 1000;
    N %= 1000;
    n.at(1) = N / 100;
    N %= 100;
    n.at(2) = N / 10;
    N %= 10;
    n.at(3) = N;

    for(int i = 0; i < (1 << 3); i++){
        int ans = n.at(0);
        for(int j = 0; j < 3; j++){
            if(i & (1 << j)) ans += n.at(j + 1);
            else ans -= n.at(j + 1);
        }
        if(ans == 7){
            cout << n.at(0);
            for(int k = 0; k < 3; k++){
                if(i & (1 << k)) cout << '+' << n.at(k+1);
                else cout << '-' << n.at(k+1);
            }
            cout << "=7" << endl;
            return 0;
        }
    }
    return 0;
}

