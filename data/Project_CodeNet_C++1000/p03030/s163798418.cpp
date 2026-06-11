#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {

    int N = 0;
    cin >> N;
    vector<tuple<string,int,int>> A(N);
    for(int i = 0; i < N; i++) {
    cin >> get<0>(A.at(i)) >> get<1>(A.at(i));
    get<1>(A.at(i)) = 100 - get<1>(A.at(i));
    get<2>(A.at(i)) = i; 
    }
    sort(A.begin(),A.end());
    for (size_t i = 0; i < N; i++)
    {
        cout << get<2>(A.at(i)) +1 << endl;
        /* code */
    }
    

    return 0;
}