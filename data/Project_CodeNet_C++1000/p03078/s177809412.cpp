#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define ALL(x) x.begin(), x.end() 
int main(){
    int X, Y, Z, K;
    cin >> X >> Y >> Z >> K;
    vector<long long> A(X), B(Y), C(Z);
    for(int i = 0; i < X; i++) cin >> A[i];
    for(int i = 0; i < Y; i++) cin >> B[i];
    for(int i = 0; i < Z; i++) cin >> C[i];
    vector<long long> sumab;
    for(int i = 0; i < X; i++){
        for(int j = 0; j < Y; j++){
            long long temp = A[i] + B[j];
            sumab.push_back(temp);
        }
    }
    sort(ALL(sumab));
    sort(ALL(C));
    vector<long long> ans;
    for(int i = 0; i < min(K, Z); i++){
        for(int j = 0; j < min(X * Y, K); j++){
            long long temp = C[Z - 1 - i] + sumab[X * Y - 1 - j];
            ans.push_back(temp);
        }
    }
    sort(ALL(ans));
    for(int i = 0; i < K; i++){
        cout << ans[(int)ans.size() - 1 - i] << endl;
    }
}