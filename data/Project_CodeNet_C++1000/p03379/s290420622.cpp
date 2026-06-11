#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N; cin >> N;
    vector<int> X(N), Y(N);
    for(int i = 0; i < N; ++i){
        cin >> X[i];
        Y[i] = X[i];
    }
    sort(X.begin(), X.end());
    //for(int i = 0; i < X.size(); ++i) cout << X[i] << " ";
    //cout << endl;
    int target = X[N/2 - 1];
    for(int i = 0; i < N; ++i){
        int now = Y[i];
        if(now <= target){
            if(N != 2) cout << X[N/2] << '\n';
            else cout << X[1] << '\n';
        }
        else{
            cout << target << '\n';
        }
    }
    return 0;
}