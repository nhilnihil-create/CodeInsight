#include <bits/stdc++.h>
using namespace std;

int main() {
    int A, B, K;
    cin >> A >> B >> K;
    vector<int> vec(0);
    for(int i=1; i<=A; i++) {
        if(A % i == 0 && B % i == 0) {
            vec.push_back(i);
        }
    }
    sort(vec.begin(),vec.end());
    reverse(vec.begin(),vec.end());
    cout << vec[K-1] << endl;
}

