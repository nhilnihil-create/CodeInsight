#include <bits/stdc++.h>
#define LL long long

using namespace std;

int main(){

    string S;
    cin >> S;

    int N = S.size();

    int sum=0;
    for(int i=0; i<N; i++){
        if(S[i] == '1')
            sum += 1;
    }

    int ans = min(N-sum,sum)*2;
        
    cout << ans << endl;
 }
