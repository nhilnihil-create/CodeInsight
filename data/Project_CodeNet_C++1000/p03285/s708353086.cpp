#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using P = pair<int,int>;
/* ちゃんと考えてわかって実装 */

int main(void){
    int n;
    cin >> n;
    int flag = 0;
    for(int i=0; i<=25; i++){
        for(int j=0; j<=15; j++){
            if(4 * i  + 7 * j == n) flag = 1;
        }
    }
    if(flag) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}