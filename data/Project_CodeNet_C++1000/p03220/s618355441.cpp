#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
int main(){
    int N;
    double T, A;
    cin >> N >> T >> A;
    vector<double> H(N);
    for(int i = 0; i < N; i++) cin >> H[i];
    double ans = 1e10;
    int ind = -1;
    for(int i = 0; i < N; i++){
        double temp = T - 0.006 * H[i];
        if(ans > abs(A - temp)){
            ans = abs(A - temp);
            ind = i;
        }
    }
    cout << ind + 1 << endl;
}