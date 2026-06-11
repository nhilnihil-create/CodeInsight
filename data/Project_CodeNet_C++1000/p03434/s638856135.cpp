#include<bits/stdc++.h>
using namespace std;
int main(){
    int N;
    cin >> N;
    vector<int> A(N);
    for(int i = 0; i < N; i++){
        cin >> A.at(i);
    }
    int Alice = 0, Bob = 0;
    sort(A.begin(), A.end());
    for(int i = 0; i < N; i++){
        if(i % 2 == 0){
            Alice += A.at(N - 1 - i);
        }
        else{
            Bob += A.at(N - 1 - i);
        }
    }
    cout << Alice - Bob << endl;
    return 0;
}