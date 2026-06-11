#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
int main(){
    long long N; 
    cin >> N;
    vector<long long> A(N);
    for(int i = 0; i< N; i++) cin >> A[i];
    map<long long, long long> m;
    m[A[0]]++;
    m[0]++;
    for(int i = 1; i < N; i++){
        A[i] += A[i - 1];
        m[A[i]]++;
    }
    long long ans = 0;
    for(auto v: m){
        ans += v.second*(v.second - 1) / 2;
    }
    cout << ans << endl;
}