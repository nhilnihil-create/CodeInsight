#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
using namespace std;
typedef long long ll;


int main(){
    string A, B, C;
    int N; cin >> N >> A >> B >> C;
    int cnt=0;
    for(int i = 0; i < N; i++){
        if(A[i] == B[i] && B[i] == C[i] && C[i] == A[i]) continue;
        else if(A[i] == B[i] && B[i] != C[i] && C[i] != A[i]) cnt++;
        else if(A[i] != B[i] && B[i] == C[i] && C[i] != A[i]) cnt++;
        else if(A[i] != B[i] && B[i] != C[i] && C[i] == A[i]) cnt++;
        else if(A[i] != B[i] && B[i] != C[i] && C[i] != A[i]) cnt+=2;
    }
    cout << cnt << endl;
}