#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main(){
    string S;
    cin >> S;
    int N = (int)S.size();
    int ans = 1000;
    for(int i = 0; i < N - 2; i++){
        int t = (S[i] - '0') * 100 + (S[i + 1] - '0') * 10 + (S[i + 2] - '0');
        ans = min(ans, abs(t - 753));
    }
    cout << ans << endl;
}