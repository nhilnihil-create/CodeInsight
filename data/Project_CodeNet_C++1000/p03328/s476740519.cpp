#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define INF 2147483647//int max
const int MOD = 1000000007;
using namespace std;
using ll = long long;
using P = pair<int,int>;


int main() {
    int a,b;
    cin >> a >> b;
    int h = 0;
    for(int i=1;i<b-a;i++){
        h += i;
    }
    cout << h-a << endl;
    return 0;
}

/*
やっほい！
　　　　　　　やほほい！
　　　　+　　 　*
　　　 ∧∧　　. ∧∞∧　*
*　ヽ(=´ω｀)人(´ω｀*)ﾉ
　.～（ O x.） （ 　 O)～　+
。*　 　∪　　　　∪
*/