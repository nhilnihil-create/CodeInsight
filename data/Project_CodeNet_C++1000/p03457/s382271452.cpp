#include<bits/stdc++.h>
using namespace std;
int main(){
    int N;
    cin >> N;
    vector<int> X(N + 1), Y(N + 1), T(N + 1);
    T.at(0) = 0;
    X.at(0) = 0;
    Y.at(0) = 0;
    for(int i = 1; i <= N; i++){
        cin >> T.at(i) >> X.at(i) >> Y.at(i);
    }
    bool ans = true;
    for(int i = 0; i < N; i++){
        int dt = T.at(i + 1) - T.at(i);
        int d = abs(X.at(i + 1) - X.at(i)) + abs(Y.at(i + 1) - Y.at(i));
        if(dt < d){
            ans = false;
        }
        if(dt % 2 != d % 2){
            ans = false;
        }
    }
    if(ans){
        cout << "Yes" << endl;
    }
    else{
        cout << "No" << endl;
    }
    return 0;
}