//
// [解法]
// この問題は、AとBの両方を隣接頂点として持つ頂点だけに限定して考えてもよいことがわかる
// （なぜなら、クヌースがそのような頂点に到達してしまった場合、次にAまたはBに進めといわれても進めなくなってしまうから、
//   最初からクヌースはそこに行けないとしてしまってもよい）
// なので、「隣接頂点にAまたはBを持たない頂点」を消す、という処理を繰り返せばよい。
// 具体的には、最初にn点全てをチェックして消すべき頂点をリストアップした後、
// 消すべき頂点を消す→その隣りを次回に削除すべき候補かチェックすべきリスト(queue)にためておく
// ということを繰り返せばよい。（計算量も頂点の数＋エッジの数程度ですむ）
// そして、その作業が終了したあと、頂点が1個以上残っていれば「Yes」としてよい
// （なぜなら、クヌースはそのうちどこか(AまたはB)の頂点からスタートして、AまたはBに移動することを永遠に続けることができるから）
// 頂点が残っていなかったら「No」になる
//
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
#define MOD 1000000007
using namespace std;

char str[200005];

int main(int argc, char* argv[])
{
    long n, m;
    scanf("%ld%ld", &n, &m);
    scanf("%s", str);

    vector<vector<long> > z(n);

    long i,j;
    for(i=0; i<m; i++) {
        long a, b;
        scanf("%ld%ld", &a, &b);
        z[a-1].push_back(b-1);
        z[b-1].push_back(a-1);
    }

    queue<long> que;
    for(i=0; i<n; i++) {
        long a=0, b=0;
        for(j=0; j<z[i].size(); j++) {
            if(str[z[i][j]]=='A') a++;
            else                  b++;
        }
        if(a==0||b==0) {
            que.push(i);
        }
    }

    vector<long> flag(n, 0);
    while( !que.empty() ) {
        long i = que.front();
        que.pop();

        if(flag[i]) continue;

        long a=0, b=0;
        for(j=0; j<z[i].size(); j++) {
            if(!flag[z[i][j]]) {
                if(str[z[i][j]]=='A') a++;
                else                  b++;
            }
        }
        if(a==0||b==0) {
            flag[i]=1;
            for(j=0; j<z[i].size(); j++) {
                if(!flag[z[i][j]]) {
                    que.push( z[i][j] );
                }
            }
        }
    }

    for(i=0; i<n; i++) {
        if(flag[i]==0) {
            printf("Yes\n"); return 0;
        }
    }
    printf("No\n");

    return 0;
}
