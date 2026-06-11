#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    long long N;
    cin >> N;
    vector<long long> X(N);
    for(int i = 0; i < N; i++)cin >> X[i];
    vector<long long> y = X;
    sort(y.begin(), y.end());
    int ind = (N - 1) / 2;
    for(int i = 0; i < N; i++){
        if(X[i] <= y[ind]){
            cout << y[ind + 1] << endl;
        }
        else cout << y[ind] << endl;
    }
}