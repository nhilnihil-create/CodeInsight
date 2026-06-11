#include <bits/stdc++.h>
#define rep(i , n) for(int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
int main (){
    int N;
    string S;
    cin >> N >> S;
    int t = 0;
    for(int i = 1; i < N - 1; i++){
        vector<int> A(26), B(26);
        int j = 0;
        for(; j <= i; j++){
            A[S[j] - 'a']++;
        }
        for(; j < N; j++){
            B[S[j] - 'a']++;
        } 
        int k = 0;
        for(int j = 0; j < 26; j++){
            if(A[j] > 0 && B[j] > 0){
                k++;
            }
        }
        t = max(t, k);
    }
    cout << t << endl;
}