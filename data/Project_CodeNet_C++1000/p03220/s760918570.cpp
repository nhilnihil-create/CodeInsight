#include<bits/stdc++.h>
using namespace std;
static const double INFTY = (1 << 20);
int main(){
    double N, T, A, h;
    cin >> N >> T >> A;
    vector<double> H(N);
    for(int i = 0; i < N; i++){
        cin >> h;
        H.at(i) = T - 0.006 * h;
    }
    double ans = 0, cc = INFTY;
    for(int i = 0; i < N; i++){
        if(abs(A - H.at(i)) < cc){
            ans = i;
            cc = abs(A - H.at(i));
        }
    }
    cout << ans + 1 << endl;
    return 0;
}