/*
　　　  ∧＿∧　やあ
　　 （´・ω・｀)　　　　　/　　　　　ようこそ、バーボンハウスへ。
　　 ／∇y:::::＼　　　 [￣]　　　　　このテキーラはサービスだから、まず飲んで落ち着いて欲しい。
　　 |:⊃:|:::::|　　　|──|
￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣|　うん、「また」なんだ。済まない。
￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣|￣　  仏の顔もって言うしね、謝って許してもらおうとも思っていない。
￣￣￣￣￣￣￣￣￣￣￣￣￣￣／|
　　　　∇　∇　∇　∇　　　／.／|　　　でも、この提出を見たとき、君は、きっと言葉では言い表せない
　　　　┴　┴　┴　┴　／ ／　  |　　　「ときめき」みたいなものを感じてくれたと思う。
￣￣￣￣￣￣￣￣￣￣|／　　  |　　　殺伐としたコンテストの中で、そういう気持ちを忘れないで欲しい
￣￣￣￣￣￣￣￣￣￣　　　　 |　　　そう思って、この提出を投げたんだ。
　　　(⊆⊇)　(⊆⊇)　(⊆⊇)　　|
　    ||　　 ||　　||　　|　　　 じゃあ、判定を聞こうか。
　　.／|＼　／|＼ ／|＼
*/

#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <array>
#include <bitset>
#include <climits>
#include <cmath>
#include <cstdio>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <string>
#include <vector>
using namespace std;
#define fst first
#define snd second
#define mp make_pair
#define ALL(obj) (obj).begin(),(obj).end()
#define FOR(i,a,b) for(lint i=(a);i<(b);i++)
#define RFOR(i,a,b) for(lint i = (b-1);i>=a;i--)
#define REP(i,n)  FOR(i,0,n)
#define RREP(i,n) RFOR(i,0,n) 
#define SIZE(x) ((int)(x).size())
#define debug(x) cerr << #x << " -> " << x << " (line:" << __LINE__ << ")" << '\n';
#define debugpair(x, y) cerr << "(" << #x << ", " << #y << ") -> (" << x << ", " << y << ") (line:" << __LINE__ << ")" << '\n';
typedef long long lint;
typedef pair<int, int> pint;
typedef pair<lint, lint> plint;
typedef vector<lint> vec;
typedef vector<vector<lint>> matrix;
typedef priority_queue<lint> p_que;
typedef priority_queue<lint, vector<lint>, greater<lint>> p_que_rev;
const lint INF = INT_MAX;
const lint LINF = LLONG_MAX;
const lint MOD = 1000000000 + 7;
const double EPS = 1e-9;
const double PI = acos(-1);
const int di[]{0, -1, 0, 1, -1, -1, 1, 1};
const int dj[]{1, 0, -1, 0, 1, -1, -1, 1};

lint n;
string s;

lint power(lint x, lint n, lint mod = MOD) {
    lint ret = 1;
    while(n > 0) {
        if(n & 1){
            (ret *= x) %= mod;
        }
        (x *= x) %= mod;
        n >>= 1;
    }
    return ret;
}

void input(){
    cin >> n;
    cin >> s;
    return;
}

void solve(){
    const lint m = power(2, n);
    lint ans = 0;
    map<pair<string, string>, lint> enum_f;
    map<pair<string, string>, lint> enum_l;
    REP(i, m){
        auto b = static_cast<bitset<20>>(i);
        string red = "";
        string blue = "";
        REP(j, n){
            if(b[j] == 0){
                red += s[j];
            }
            else {
                blue += s[j];
            }
        }
        auto p = make_pair(red, blue);
        enum_f[p]++;
    }
    REP(i, m){
        auto b = static_cast<bitset<20>>(i);
        string red = "";
        string blue = "";
        REP(j, n){
            if(b[j] == 0){
                red += s[j+n];
            }
            else {
                blue += s[j+n];
            }
        }
        reverse(ALL(blue));
        reverse(ALL(red));
        auto p = make_pair(blue, red);
        enum_l[p]++;
    }
    for (auto e : enum_f){
        auto key = e.fst;
        lint value = e.snd;
        if(enum_l.find(key) == enum_l.end()){
            continue;
        }
        else {
            lint value2 = enum_l.at(key);
            ans += value * value2;
        }
    }
    cout << ans << endl;
    return;
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    input();
    solve();
    return 0;
}