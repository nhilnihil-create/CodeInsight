#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    int A , B , K;
    cin >> A >> B >> K;
    for(int i = A; i <= min(B , A + K - 1); i++){
        cout << i << endl;
    }
    for(int i = max(A + K , B - K + 1); i <= B; i++){
        cout << i << endl;
    }
}