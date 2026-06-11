#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> a(N);
    for(int i = 0; i < N; i++){
        cin >> a.at(i);
    }
    for(int i = 0; i < N - 1; i++){
        for(int j = i + 1; j < N; j++){
            if(a.at(i) < a.at(j)){
                int t = a.at(i);
                a.at(i) = a.at(j);
                a.at(j) = t;
            }
        }
    }
    int Alice = 0;
    int Bob = 0;
    for(int i = 0; i < N; i++){
        if(i % 2 == 0){
            Alice += a.at(i);
        }else{
            Bob += a.at(i);
        }
    }
    int dif = Alice - Bob;
    cout << dif << endl;
}