#include<iostream>
#include<string>
#include<vector>
#include <algorithm>
#include <map>
using namespace std;
int main() {
    long long  N;
    cin >> N;
    vector<long long> L(N+1);
     L.at(0) = 2;
     L.at(1) = 1;
    for(long long i=0;i<=N-2;i++){
        L.at(i+2) = L.at(i+1) + L.at(i) ;
    }
    cout << L.at(N) << endl;
}