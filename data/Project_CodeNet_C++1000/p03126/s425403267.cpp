#include <bits/stdc++.h>
#define rep(i , n) for (int i = 0; i < (int)(n); i++)
const int INF = 1<<29;
using namespace std;
using ll = long long;
vector <int> F(30);
int main(){
    int N , M;
    cin >> N >> M;
    vector <int> K(N);
    for(int i = 0; i < N; i++){
        cin >> K[i];
        for(int j = 0; j < K[i]; j++){
            int A;
            cin >> A;
            F[A - 1]++;
        }
    }
    int best_food = 0;
    for(int i = 0; i < M; i++){
        if(F[i] == N){
            best_food++;
        }
    }
    cout << best_food << endl;
}