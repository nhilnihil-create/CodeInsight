#include <bits/stdc++.h>
using namespace std;
 
long long Lucus(int n);

int main() {
    int N;
    cin >> N;
    vector<long long> Lucus(N+1);

    Lucus.at(0) = 2LL;
    Lucus.at(1) = 1LL;

    for(int i = 2; i <= N; i++){
        Lucus.at(i) = Lucus.at(i-1) + Lucus.at(i-2);
    }

    cout << Lucus.at(N);
}