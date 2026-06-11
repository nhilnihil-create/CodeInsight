#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;

int main(){
    int N;
    cin >> N;
    vector<int> vec(N);
    for(int i = 0; i < N; i++){
        cin >> vec[i]; 
    }
    sort(vec.begin(), vec.end());
    int a;
    a = vec[N-1] - vec[0];
    cout << a << endl;
}