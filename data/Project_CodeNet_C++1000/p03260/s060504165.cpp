#include <bits/stdc++.h>
using namespace std;
int main(void){
    int A,B;
    string ans;
    ans = "No";
    cin >> A >> B;
    for(int i = 1; i <= 3;i++){
        if((A * B * i) % 2 != 0 ){
            ans = "Yes";
            break;
        }
    }
    cout << ans << endl;
}
