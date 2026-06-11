#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector<int> v(M+1);

    for(int i=0; i<N; i++) {
        int k;
        cin >> k;
        for(int j=0; j<k; j++) {
            int x;
            cin >> x;
            v[x]++;
        }
    }

    int count = 0;
    for(int i=0; i<v.size(); i++) {
        if(v[i] == N) {
            count++;
        }
    }
    cout << count << endl;
}

