#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    int T;
    int A;
    cin >> N >> T >> A;
    vector<double> H(N);
    for (int i = 0; i < N; i++)
    {
        cin >> H.at(i); 
    }
    for (int i = 0; i < N; i++)
    {
        H.at(i) = A - ( T - H.at(i) * 0.006);
        if(H.at(i)<0) H.at(i) *= -1;
    }
    int ans = 1;
    double tmp = H.at(0);
    for (int i = 1; i < N; i++)
    {
        if(tmp > H.at(i)){
            tmp = H.at(i);
            ans = (i+1);
        }
    }
    cout << ans << endl;
}