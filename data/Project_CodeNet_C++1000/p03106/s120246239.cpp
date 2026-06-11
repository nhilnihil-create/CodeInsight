#include <bits/stdc++.h>
using namespace std;

int main() {
    int A, B, K;
    cin >> A >> B >> K;
    vector<int> v;
    for(int i=1; i<=A; i++) {
        if(A % i == 0 && B % i == 0) {
            v.push_back(i);
        }
    }
    reverse(v.begin(),(v.begin(),v.end()));
    cout << v[K-1] << endl;
}

