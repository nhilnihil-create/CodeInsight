#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
int main(){
    int N, T, A, ans = 0;
    cin >> N >> T >> A;
    vector<int> H(N);
    vector<double> t(N);
    for(int i = 0; i < N; i++){
        cin >> H[i];
        t[i] = abs(A - (T - H[i] * 0.006));
    }
    for(int i = 1; i < N; i++){
        if(t[ans] > t[i]){
            ans = i;
        }
    }
    cout << ans + 1 << endl;
}