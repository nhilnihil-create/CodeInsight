#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int> P;
int INF = 1e9+7;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
signed main() {
    string S;
    cin >> S;
    if(S == "AKIHABARA" || S == "AKIHABAR" || S == "AKIHABRA" ||
       S == "AKIHBARA" || S == "KIHABARA" || S == "AKIHABR" ||
       S == "AKIHBAR" || S == "KIHABAR" || S == "AKIHBRA" ||
       S == "KIHABRA" || S == "KIHBARA" || S == "KIHBRA" ||
       S == "KIHBAR" || S == "KIHABR" || S == "AKIHBR" ||
       S == "KIHBR") {
        puts("YES");
    }
    else {
        puts("NO");
    }
}