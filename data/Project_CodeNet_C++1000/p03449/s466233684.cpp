#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int N;
    cin >> N;
    vector<int> I(N), J(N);
    int a, b;
    for(int i = 0; i < N; i++){
        cin >> a;
        I.at(i) = a;
    }
    for(int i = 0; i < N; i++){
        cin >> b;
        J.at(i) = b;
    }
    
    int ans = 0, num;
    for(int i = 0; i < N; i++){
        num = 0;
        for(int j = 0; j <= i; j++){
            num += I.at(j);
        }
        for(int k = i; k < N; k++){
                num += J.at(k);
            }
        ans = max(ans, num);
    }
    cout << ans << endl;
}