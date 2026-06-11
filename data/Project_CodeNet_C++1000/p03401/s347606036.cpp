#include <bits/stdc++.h>
using namespace std;
int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    for(int i = 0; i < N; i++) {
        cin >> A.at(i);
    }

    int total = 0;
    int pos = 0;
    int current, next;
    vector<int> cost(N);
    for(int i = 0; i < N; i++) {
        current = A.at(i);
        total += abs(current - pos);
        next = (i == N - 1) ? 0 : A.at(i + 1);
        if((pos <= current && current <= next) || (pos >= current && current >= next)){
            cost.at(i) = 0;
        }
        else{
            if(pos < current) {
                cost.at(i) = (current - max(pos, next)) * 2;
            } else {
                cost.at(i) = (min(pos, next) - current) * 2;
            }
        }
        pos = A.at(i);
    }
    total += abs(pos);

    for(int i = 0; i < N; i++) {
        cout << (total - cost.at(i)) << endl;
    }

    return 0;
}