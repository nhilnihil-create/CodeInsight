#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(void){
    //int A,B,C,D;
    string temp;
    cin >> temp;
    /*
    A = temp[0] - '0';
    B = temp[1] - '0';
    C = temp[2] - '0';
    D = temp[3] - '0';
    */
    char op[3];
    rep(i,8){
        int sum = temp[0] - '0';
        
        rep(j,3){
            if(i & (1 << j)){
                op[j] = '+';
                sum += temp[j+1] - '0';
            }else{
                op[j] = '-';
                sum -= temp[j+1] -'0';
            }
        }
        if(sum == 7) break;
    }
    string ans;
    
    rep(i,3){
        cout << temp[i] << op[i] ;
    }
    //ans = temp[3];
    
    cout << temp[3] << "=7"<< endl;
    return 0;
}