#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
#define REP(i, n) for(int i=0; i<n; i++)

int main(){
    string S;
    cin >> S;
    int N = S.length();

    char last = S[0];
    int K = N;
    for(int i = 1; i < N; i++){
        char c = S[i];
        if(last != c){
            int front = i;
            int back = N-i;
            K = min(K, max(front, back));
        }
        last = c;
    }

    cout << K << endl;
    return 0;
}
