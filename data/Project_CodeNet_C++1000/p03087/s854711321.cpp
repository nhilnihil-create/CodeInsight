#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include <queue>
using namespace std;
using ll = long long;

int N,Q;
string S;
ll L[110000];
ll R[110000];
char ch[110000];

int main(void){

    ll ans = 0;

    cin >> N >> Q;
    cin >> S;
    for (int i = 1; i <= Q;i++) cin >> L[i] >> R[i];

    for (int i = 1; i <= N; i++){
        ch[i] = S[i-1]; //chは[0]から始まるので注意！
    }

    ll times = 0;
    ll T[N+1];
    T[0] = 0;

    bool AL = false;

    for (int i = 1; i <= N; i++){
        if(ch[i] == 'A') {
            AL = true;
        } else if(AL){
            if (ch[i] == 'C'){
                times++;
            } 
            AL = false;
        }
        T[i] = times;
    }

    for (int i = 1; i <= Q; i++){
        ans = T[R[i]] - T[L[i]-1];
        if (T[L[i]] - T[L[i]-1] == 1){
            ans--;
        }
        cout << ans << endl;
        ans = 0;
    }



    return 0;
}