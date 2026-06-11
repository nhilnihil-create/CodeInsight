#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;

int main(){
    int N , X, sum;
    sum = 0;
    cin >> N >> X;
    vector<int> vec(N);
    for(int i = 0; i < N; i++){
        cin >> vec[i];
        sum += vec[i];
    }
    sort(vec.begin(),vec.end());
    cout << N + ((X - sum) / vec[0]) << endl;
}