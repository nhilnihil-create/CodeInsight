#include <bits/stdc++.h>
using namespace std;
 
int main() 
{
    string S = "MARCH";
    long long C[5] = {0};
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        string str;
        cin >> str;
        for (int j = 0; j < 5; j++) {
            if(str[0] == S[j]){
                C[j]++;
            }
        }
    }
    
    long long ans = 0;
    for (int i = 0; i < 5; i++) {
        for (int j = i+1; j < 5; j++) {
            for (int k = j+1; k < 5; k++) {
                ans += C[i] * C[j] * C[k];
            }
        }
    }
    cout << ans << endl;
}