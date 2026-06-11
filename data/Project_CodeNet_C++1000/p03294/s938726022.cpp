#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
using namespace std;

int main() {
    int N;
    cin >> N;
    long long int ans =0;

    for(int i=0; i<N; i++){
        int c;
        cin >> c;
        ans += c-1;
    }

    cout << ans << endl;
}