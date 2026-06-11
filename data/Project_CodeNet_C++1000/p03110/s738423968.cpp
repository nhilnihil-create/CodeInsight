#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define INF 1e9;
using namespace std;
using ll = long long;
int main() {
    int N;
    double money = 0.0;
    cin >> N;
    vector <double> A(N);
    vector <string> B(N);
    for(int i = 0; i < N; i++){
        cin >> A[i] >> B[i];
        if(B[i] == "JPY"){
            money += A[i];
        }
        else{
            money += A[i] * 380000.0;  
        }
    }
    cout << money << endl;
}
