#include <iostream>
#include <vector>
//#include <string>
#include <string.h>
#include <algorithm>

using namespace std;

#define rep(i,n) for(int i = 0; i < (n); ++i)
 
typedef long long ll;
typedef char str255[256];

#define BIG_PRIME 1'000'000'007
#define BP_remainder(x) ((x) % BIG_PRIME)

const int INF = 1 << 30;
const int INF_NEG = INF * -1;
const ll INF_LONG = 1LL << 62;
const ll INF_LONG_NEG = INF_LONG * -1;

int main()
{
    char S[55]; cin >> S;
    int lenS = strlen(S);
    
    bool used[260]; rep(i, 260) used[i] = false;

    rep(i, lenS){
        int code = S[i];
        if (used[code]){
            puts("-1"); return 0;
        }
        used[code] = true;
    }

    if (lenS < 26){  // 使われていない文字がある場合は一番小さい文字を追加
        for (char c = 'a'; c <= 'z'; ++c){
            if(!used[c]){
                S[lenS] = c;
                S[lenS + 1] = '\0';
                cout << S << endl;
                return 0;
            }
        }
    } else { // 既に全ての文字が使われている場合
        used[S[25]] = false;
        for (int ptr = 24; ptr >= 0; --ptr){
            char deleteChar = S[ptr];
            used[deleteChar] = false;
            for (char c = deleteChar + 1; c <= 'z'; ++c){
                if (!used[c]){
                    S[ptr] = c;
                    S[ptr + 1] = '\0';
                    cout << S << endl;
                    return 0;
                }
            }
        }
        puts("-1"); // 新たに多彩な単語が作れなかった場合
    }

    return 0;
}
