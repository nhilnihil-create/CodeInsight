#include <iostream>
#include <iomanip>
#include <string>

using namespace std;


int main(){
    int N;
    cin >> N;
    string A, B, C;
    cin >> A >> B >> C;

    int ans = 0;
    for (int i = 0; i < N; i++){
        if (A[i] == B[i]){
            if (A[i] != C[i]){
                ans ++;
            }
        }else if(A[i] == C[i]){
            ans ++;
        }else if(B[i] == C[i]){
            ans ++;
        }else{
            ans += 2;
        }
    }
    
    cout << ans << endl;

    return 0;
}