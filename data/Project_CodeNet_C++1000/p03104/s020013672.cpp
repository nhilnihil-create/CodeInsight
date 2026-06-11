#include <iostream>
#include <vector>
using namespace std;
int main(){
    long long A, B;
    cin >> A >> B;
    if(A % 2 == 0 && B % 2 == 0){
        long long C = B - A + 1;
        long long cnt = C / 2;
        if(cnt % 2 == 0) cout << B << endl;
        else {long long ans = B ^ 1;
        cout << ans << endl;
        }
    }
    else if(A % 2 == 0 && B % 2 == 1){
        long long C = B - A + 1;
        if(C / 2 % 2 == 0) cout << 0 << endl;
        else cout << 1 << endl;
    }
    else if(A % 2 == 1 && B % 2 == 0){
        long long C = B - A;
        long long ans;
        if(C / 2 % 2 == 0){
            ans = A ^ B;
        }
        else ans = A^ B ^ 1;
        cout << ans << endl;
    }
    else{
        long long cnt = (B - A + 1) / 2;
        if(cnt % 2 == 0){
            cout << A << endl;
        }
        else{
            long long ans = A^1;
            cout << ans << endl;
        }
    }
}