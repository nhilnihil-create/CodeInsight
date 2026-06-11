#include<bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    while (true) {
        string S = to_string(N);
        map <char, int> cnt;
        for (char s : S) {
            cnt[s]+=1;
        }
        if (cnt.size()==1) {
            cout << S;
            return 0;
        }
        N++;
    }
}