#include <bits/stdc++.h>
using namespace std;
using int64 = long long;
#define int int64
#define rep(i, n) for(int i=0; i<n; i++)
#define FOR(i, a, b) for(int i=a; i<b; i++)
#define SORT(x) sort(x.begin(), x.end())
#define GSORT(x) sort(x.begin(), x.end(), greater<int>())
#define mk make_pair
#define fi first
#define se second
#define pb push_back
#define ALL(x) x.begin(), x.end()
#define V(T) vector<T>
typedef pair<int, int> P;
typedef pair<P, P> PP;
typedef vector<int> vi;
typedef vector<vi> vvi;
int max(int a, int b) {if(b>a) return b; else return a;}
int min(int a, int b) {if(b<a) return b; else return a;}

const int INF = 1e18;

signed main() {
    string S;
    cin >> S;
    int n = S.size();

    int res = INF;

    //例えばA01B(AとBは任意の01文字列)があったとき、A0か1Bのどちらかを反転すれば、
    //01(i文字目とi+1文字目が異なる部分)を1つ消去できる。
    //Kを最大にするため、A0か1Bの長い方の長さを取ればよい。
    //このような操作をi文字目とi+1文字目が異なるすべてのiについて考え、その最小値が
    //答えである。なぜなら、仮の解をtとして、i文字目とi+1文字目が異なり、
    //i<tかつn-i<tであるようなiが存在するとき、長さt以上にわたる反転操作は、必ずi文字目と
    //i+1文字目を同時に巻き込んでしまい、i文字目とi+1文字目を等しくすることが出来ないからである。
    //逆に、i>=tまたはn-i>=tであれば、どちらかの文字だけを含む連続するt文字を反転できるので、
    //i文字目とi+1文字目を等しくできる。tが最小値であれば、これをi文字目とi+1文字目が異なる
    //全てのiについて行うことが出来る。

    rep(i, n-1) {
        if(S[i]!=S[i+1]) {
            res = min(res, max(i+1, n-i-1));
        }
    }

    if(res==INF) res = n;

    cout << res << endl;
 
    return 0;
}