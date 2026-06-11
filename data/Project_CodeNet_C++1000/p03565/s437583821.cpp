#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> iint;
typedef pair<ll,ll> llll;
#define ALL(x) (x).begin(),(x).end()
const ll zero = 0;
const ll INF = 3000000000000000000; //10^18
const int inINF = 1000000000; //10^9
const ll MOD = 1000000007; //10^9+7
const ll MOD2 = 998244353;

int main(){
    string S, T;
    cin >> S >> T;
    int a, b;
    a = S.length();
    b = T.length();
    if(a < b){
        printf("UNRESTORABLE\n");
        return 0;
    }

    bool check;
    for (int i = a-b; i >= 0; i--) {
        check = true;
        for (int j = 0; j < b; j++) {
            if(S[i+j] != '?' && S[i+j] != T[j]){
                check = false;
                break;
            }
        }
        if(check == true){
            for (int j = 0; j < a; j++) {
                if(j >= i && j <= i + b - 1){
                    printf("%c", T[j-i]);
                }
                else{
                    if(S[j] == '?'){
                        printf("a");
                    }
                    else{
                        printf("%c", S[j]);
                    }
                }
            }
            return 0;
        }
    }
    
    printf("UNRESTORABLE\n");

}