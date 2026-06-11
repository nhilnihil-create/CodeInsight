#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, T, A;
    cin >> N >> T >> A;
    int B[N];
    for (int i=0; i<N; i++) cin >> B[i];
    double min_diff=10000000;
    int a;
    double x[N], diff[N];
    for (int i=0; i<N; i++){
        x[i]=T-B[i]*0.006;
        diff[i]=abs(x[i]-A);
        if (diff[i]<=min_diff){
            min_diff=diff[i];
            a=i;
        }
    }
    cout << a+1 << endl;
}
