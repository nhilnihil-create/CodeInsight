#include <bits/stdc++.h>
using namespace std;
 
int main(){
    int N;
    cin >> N;

    string A, B, C;
    cin >> A >> B >> C;

    int ans = 0;

    for (int i = 0; i < N; i++){
        if (A.substr(i, 1) == B.substr(i, 1) && B.substr(i, 1) != C.substr(i, 1)){
            ans++;
        }
        else if (B.substr(i, 1) == C.substr(i, 1) && A.substr(i, 1) != B.substr(i, 1)){
            ans++;
        }
        else if (A.substr(i, 1) == C.substr(i, 1) && A.substr(i, 1) != B.substr(i, 1)){
            ans++;
        }
        else if (A.substr(i, 1) != B.substr(i, 1) && B.substr(i, 1) != C.substr(i, 1) && A.substr(i, 1) != C.substr(i, 1)){
            ans += 2;
        }
    }

    cout << ans << endl;
}