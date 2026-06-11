#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(N) for (int i = 0; i < N; i++)

int main(){
    int N;
    cin >> N;
    int arrival_time;
    int leave_time;
    vector<int> C(N-1);
    vector<int> S(N-1);
    vector<int> F(N-1);
    for (int i = 0; i < N - 1; i++){
        cin >> C[i] >> S[i] >> F[i];
    }

    for (int i = 0; i < N; i++){
        if (i == N - 1){
            cout << 0 << endl;
            break;
        }
        for (int j = i; j < N - 1; j++){
            if (j == i){
                arrival_time = S[j] + C[j];
            }else{
                leave_time = S[j];
                while(leave_time < arrival_time){
                    leave_time += F[j];
                }
                arrival_time = leave_time + C[j];
            }
        }
        cout << arrival_time << endl;
    }
}
