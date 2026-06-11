#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> d(N);
    for(int i = 0; i < N; i++){
        cin >> d.at(i);
    }
    int stage = N;
    for(int i = 0; i < N - 1; i++){
        for(int j = i + 1; j < N; j++){
            if(d.at(i) < d.at(j)){
                int t = d.at(i);
                d.at(i) = d.at(j);
                d.at(j) = t;
            }
        }
    }
    for(int i = 0; i < N - 1; i++){
        if(d.at(i) == d.at(i + 1)){
            stage--;
        }
    }
    cout << stage << endl;
}