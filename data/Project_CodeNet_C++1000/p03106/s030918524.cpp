#include <bits/stdc++.h>
using namespace std;

int main(){
    int A, B, K;
    cin >> A >> B >> K;
    vector<int> V;
    for (int i = 1; i <= min(A, B); i++)
    {
        if(A % i == 0 && B % i == 0) V.push_back(i);
    }
    for (int i = 0; i < K - 1; i++) V.pop_back();
    cout << V.back() << "\n";
    return 0;
}