#include <iostream>
#include <algorithm>
#include <bitset>
#include <math.h>
#include <string>
#include <map>
#include <vector>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define rep(i, n) for (int i = 0; i < n; i++)
#define LargeNum 1000000007
typedef pair <double, double> P;

int main(){
    int N, time;
    cin >> N;
    int C[N-1], S[N-1], F[N-1];
    rep(i, N-1) cin >> C[i] >> S[i] >> F[i];
    rep(j, N){
        time = 0;
        for (int i=j; i<N-1; i++){
            if (time < S[i]) time = S[i];
            else {
                while(time % F[i] != 0) time ++;
            }
            time += C[i];
        }
        cout << time << endl;
    }
    return 0;
}
