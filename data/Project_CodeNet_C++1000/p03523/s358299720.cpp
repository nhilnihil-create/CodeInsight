#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
const string akiba[16] = {
"KIHBR", "KIHBRA", "KIHBAR", "KIHBARA",
"KIHABR", "KIHABRA", "KIHABAR", "KIHABARA",
"AKIHBR", "AKIHBRA", "AKIHBAR", "AKIHBARA",
"AKIHABR", "AKIHABRA", "AKIHABAR", "AKIHABARA"
};

int main(){

    // 1. 入力情報.
    char c[55];
    scanf("%s", c);
    string S(c);
    
    // 2. 比較.
    bool ok = false;
    rep(i, 16){
        if(S == akiba[i]){
            ok = true;
            break;
        }
    }
    
    // 3. 出力.
    if(ok) puts("YES");
    else   puts("NO");
    return 0;
    
}