#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;

int main() {
	cin.tie(0);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;

    vector<int> A;

    for(int i = 11; A.size() != N; i += 10) {
        bool checker = false;
        for(int j = 2; j * j <= i; j++) {
            if(i % j == 0) {
                checker = true;
                break;
            }
        }
        if(checker) continue;
        A.push_back(i);
    }

    for(int i = 0; i < N; i++) {
        cout << A[i] << " ";
    }

    cout << endl;
}