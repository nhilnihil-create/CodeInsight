/*************************************
＜最初に考えたこと＞
AiとBiの差が0になると終了だから、
先手は差をなるべく差が大きくなるように、後手は差が小さくなるようにするのが最善かな？
そうすると先手は、Ai<BiというAiから1を引いていくのがよいけど、
それで0になったらそれ以上は引けないので、それ以降は差が小さくなる手を打つしかない。
一方でBは差が小さくなる手を打ち続ける。
⇒
まとめると、Ai-Biの絶対値の和をSとするとき、
先手が Ai<BiというAiから1を引いていく間は1ターンしてもSが変化しない。
そのあとは1ターンごとに先手と後手あわせてSを2減らしていき、0になったら終了。
ということで解けました。
⇒ 間違いです（考察ミス）

＜間違いの内容＞
先手の手番のとき、
Ai>Bi の場合は、Aiを1減らすと差が1減ってしまうのだけど、
Ai=Bi の場合は、Aiを1減らせば差が1増えるんですね。
だから先手はそう簡単には負けない。
3 2
2 2
0 1
みたいな状況のときは、3を減らしたら終わってしまうけど、2を減らせばまだ勝負を続けられる。

＜解答＞
逆に、どういう場合に終わってしまうかというと、終了直前の先手番の盤面は
0 0
6 5
0 1
0 0
みたいに、0でないAiが1個だけ残るような場合だけとわかる。そのあとの最終形は
0 0
5 5
0 0
0 0
というもの。
先手としては、この最後に残る数(上の例では5)を最小化したい。
→
先手としては、最初に Ai>Bi であるもののうち Bi が最小のものを残す
（それ以外のAiから引いていく）という戦略が最善で、実際にそれでうまくいくことがわかる。
************************************/

#include <stdio.h>
#include <string>
#include <cstring>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <list>
#include <iterator>
#include <assert.h>
#pragma warning(disable:4996) 

typedef long long ll;
#define MIN(a, b) ((a)>(b)? (b): (a))
#define MAX(a, b) ((a)<(b)? (b): (a))
#define LINF 9223300000000000000
#define INF 2140000000
const long long MOD = 1000000007;
using namespace std;

int main(int argc, char* argv[])
{
    int n;
    scanf("%d", &n);
    ll sum=0;
    int val=INF;
    int i;
    for(i=0; i<n; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        if(a>b) val=MIN(val,b);
        sum += a;
    }
    if(val==INF) {
        printf("0\n");
    }
    else {
        printf("%lld\n", sum-val);
    }

    return 0;
}

