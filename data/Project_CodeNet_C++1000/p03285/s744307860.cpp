#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;
    string ans = "No";
    for(int i = 0; i <= N; i++) {
        for(int j = 0; j <= N; j++) {
            if(N == 4*i + 7*j) {
                ans = "Yes";
            }
        }
    }
    cout << ans << endl;
}