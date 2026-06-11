#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG

int main() {
    int N;
    cin >> N;
    vector<int> an(N);
    for (int i = 0; i < N; i++) 
        cin >> an[i];
    
    sort(an.begin(), an.end(), greater<int>());
    int Alice_score = 0;
    int Bob_score = 0;
    for (int i = 0; i < N; i++) {
        if (i % 2 == 0)
            Alice_score += an[i];
        if (i % 2 == 1)
            Bob_score += an[i];
    }
    cout << Alice_score - Bob_score << endl;
}