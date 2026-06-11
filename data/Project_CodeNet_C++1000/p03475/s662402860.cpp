#include <bits/stdc++.h>
using namespace std;
 
int main() 
{
    int N;
    cin >> N;
    
    int C[510], S[510], F[510];
    for (int i = 0; i < N-1; i++){
        cin >> C[i] >> S[i] >> F[i];
    }
    for (int i = 0; i < N; i++) {
        int sum = 0;
        for (int j = i; j < N-1; j++) {
            if (sum < S[j]) {
                sum = S[j];
            }else if(sum % F[j] == 0){
            }else{
                sum = sum + F[j] - sum % F[j];
            }
            sum += C[j];
        }
        cout << sum << endl;
    }
}