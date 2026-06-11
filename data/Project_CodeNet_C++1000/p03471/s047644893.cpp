#include <bits/stdc++.h>
#define rep(i , n) for (int i = 0; i < (int)(n); i++)
const int INF = 1<<29;
using namespace std;
using ll = long long;
int main(){
    int N , Y , A=-1 , B=-1 , C=-1;
    cin >> N >> Y;
    Y /= 1000;
    for(int i = 0; i <= N; i++){
        for(int j = 0; j <= N - i; j++){
            if(9 * i + 4 * j + N == Y){
                A = i;
                B = j;
                C = N - i - j;
            }
        }
    }
    cout << A << " " << B << " " << C << endl;
}