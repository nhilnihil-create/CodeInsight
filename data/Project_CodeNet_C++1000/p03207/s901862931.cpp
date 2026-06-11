#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;
    vector<int> price(N);
    for(int i = 0; i < N; i++){
        cin >> price.at(i);
    }

    sort(price.begin(),price.end());
    
    int M = price.at(N-1) / 2;
    int total = 0;

    for(int i = 0; i < N - 1; i++){
        total += price.at(i);
    }

    cout << total + M << endl;

}