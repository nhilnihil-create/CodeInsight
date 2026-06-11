#include <bits/stdc++.h>          
using namespace std;    
typedef long long ll;           

int main() {
    int N;
    cin >> N;
    vector<ll> a(N);
    for (int i=0; i<N; i++) {
        cin >> a.at(i);
    }

    ll count = 0;
    for (int i=0; i<N; i++) {
        while (a.at(i)%2 == 0) {
            a.at(i) /= 2;
            count++;
        }
    }
    
    
    
    cout << count << endl;
}