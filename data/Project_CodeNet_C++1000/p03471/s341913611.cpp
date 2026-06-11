#include<bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;

int main(){
    int N, Y;
    cin >> N >> Y;
    for(int i = 0; i <= N && i * 10000 <= Y; i++){
        for(int j = 0; j <= N - i && j * 5000 <= Y - i * 10000; j++)
            if(i * 10000 + j * 5000 + (N - i - j) * 1000 == Y){
                cout << i << " " << j << " " << N - i - j << endl;
                return 0;
            }
    }
    cout << -1 << " " << -1 << " " << -1 << endl;
    return 0;
}