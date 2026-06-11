#include<bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    long long ans=-N;
    for (long long i=0; i<N; i++) {
        long long a;
        cin >> a;
        ans+=a;
    }
    cout << ans;
}