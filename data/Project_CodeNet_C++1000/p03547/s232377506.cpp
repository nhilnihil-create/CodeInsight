/*
ABC119-D
問題
A社の神社とB軒の寺がある。
西からi社目の神社はsiメートル、i軒目の寺はtiメートルの地点
があります。
以下Q個の問いに答える。
問i:道路のxiメートルの地点から出発して自由に移動したとき、
神社1社と寺1軒に訪れるのに必要な最小の移動距離は何メートルか。
制約
1<=A,B<=10^5
1<=Q<=10^5
1<=si,ti,xi<=10^10
方針
単純にxiに一番近い神社と寺に行くのが最短距離なのはわかる。
ただし、パターンとしては以下があるので、全パターン試す。
・最初に前方最寄りの神社に行き、前方最寄りの寺にいく
・最初に前方最寄りの神社に行き、後方最寄りの寺にいく
・最初に後方最寄りの神社に行き、前方最寄りの寺にいく
・最初に後方最寄りの神社に行き、後方最寄りの寺にいく
・最初に前方最寄りの寺に行き、前方最寄りの神社にいく
・最初に前方最寄りの寺に行き、後方最寄りの神社にいく
・最初に後方最寄りの寺に行き、前方最寄りの神社にいく
・最初に後方最寄りの寺に行き、後方最寄りの神社にいく
最寄りを調べるためには以下の二分探索を用いる(O(logN))
lower_bound
・探索したい値以上が現れる最初の位置のイテレータ
v ={1,2,3,4,5} x = 3だったら、index:2の位置のイテレータ
upper_bound
・探索したい値より大きい値が現れる最初の位置のイテレータ
v ={1,2,3,4,5} x = 3だったら、index:3の位置のイテレータ
・前方のindex(自分自身を含む)
upper_bound(v.begin(), v.end(), x) - v.begin() - 1
・前方のindex(自分自身を含まない)
lower_bound(v.begin(), v.end(), x) - v.begin() - 1
・後方のindex(自分自身を含む)
lower_bound(v.begin(), v.end(), x) - v.begin()
・後方のindex(自分自身を含まない)
upper_bound(v.begin(), v.end(), x) - v.begin()
*/

#include <bits/stdc++.h>
#include <math.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
#define rrep(i, n) for(int i = 0; i <= (n); i++)
using namespace std;
typedef long long ll;
const int MOD = 1000000007;
const ll INF = 1LL<<60;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
using Graph = vector<vector<int>>;

typedef pair<int, int> P;

int main(){
    char X, Y; cin >> X >> Y;
    if (X < Y){
        cout << "<" << endl;
    }
    else if (X==Y){
        cout << "=" << endl;
    }
    else{
        cout << ">" << endl;
    }
}