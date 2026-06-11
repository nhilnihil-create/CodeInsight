#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int N;
    cin >> N;
    vector<ll> vec(N);
    for(int i = 0; i < N; i++){
        cin >> vec.at(i);
    }

    int ans = 0;
    for(ll i = 0; i < N; i++){
        if(vec.at(i) % 2 == 0){
            for(int j = 0; j < 1000000000; j++){
                vec.at(i) /= 2;
                ans++;
                if(vec.at(i) % 2 != 0) break;
            }
        }
    }
    cout << ans << endl;
}