#include <bits/stdc++.h>
using namespace std;
int N;
vector<int> A(100), B(100), C(100), D(100);
int answer = 0;

void input() { 
    cin >> N; 
    for(int i = 0; i < N; i++) cin >> A.at(i) >> B.at(i);
    for(int i = 0; i < N; i++) cin >> C.at(i) >> D.at(i);
}

void solve() {
    vector<int> count(N,0);
    int answer = 0;
    
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if (A.at(i) < C.at(j) && B.at(i) < D.at(j)) count.at(i) = count.at(i) + 1;
        }
    }

    vector<int> used(N, 0);
    for (int i = 1; i <= N; i++) {
        for(int j = 0; j < N; j++) {
            if (count.at(j) == 0) continue;
            if (count.at(j) == i) {
                for (int k = 0; k < N; k++) {
                    if (used.at(k) != 0) continue;
                    if (A.at(j) < C.at(k) && B.at(j) < D.at(k)) {
                        answer++;
                        used.at(k) = 1;
                        break;
                    }
                }
            }
        }
    }
}


int main() {
    input();

    vector<pair<int, int>> blue(N);
    for(int i = 0; i < N; i++) {
        blue.at(i).first = C.at(i);
        blue.at(i).second = D.at(i);
    }
    sort(blue.begin(), blue.end());
    vector<int> used(N, 0);
    for (int i = 0; i < N; i++) {
        int maxRedY = -1;
        int maxRedJ = -1;
        for(int j = 0; j < N; j++){
            if (used.at(j) != 0) continue;
            if (blue.at(i).first > A.at(j) && blue.at(i).second > B.at(j)) {
                if (B.at(j) > maxRedY) maxRedJ = j;
                maxRedY = max(B.at(j), maxRedY);
            }
        }
        if(maxRedJ != -1) {
            answer++;
            used.at(maxRedJ) = 1;
        }
    }

    cout << answer << endl;

    return 0;
}