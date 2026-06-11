#include<bits/stdc++.h>
typedef long long ll;
#define REP(i,n) for (int i = 0; i < (n); ++i)
#define FOR(i,m,n) for (int i = m; i < (n); ++i)
#define REPR(i,n) for (int i = n; i >= 0; --i)
#define P pair<int, int>
const int INF = 1e9;
using namespace std;

int contest,goal;

int main() {
    //ボーナスとるかとらないかをbit全探索で表現
    //ボーナス
    cin >> contest >> goal;
    goal /= 100; // 100かける処理を省くため
    int theNumberOfProblems[contest];
    int bonus[contest];
        int ans = 100000000;//これを更新して最小値を出力
    REP(i,contest) {
        cin >> theNumberOfProblems[i] >> bonus[i];
        bonus[i] /= 100;
    }
    REP(x,1<<contest) {
        int score=0;
        int cnt=0;
        //ボーナスを加算していって、ボーナスだけでゴールを超えないぎりぎりの回でポイントを加算していく
        //ギリギリの回は、theNumberOfProblemsのインデックスが大きい順で見ていく
        REP(i,contest) /*各ビットの検査*/{
            if(x&(1<<i)) {
                //ある回の問題数すべてとボーナスをスコアに加算
                cnt+=theNumberOfProblems[i];
                score+=bonus[i]+theNumberOfProblems[i]*(i+1);
            }
        }
        //scoreがgoal以上なら、最小値を更新し、次のパターンへ
        if(score >= goal) {
                ans=min(ans,cnt);
                continue;
            }
        //もし、不足していれば得点が大きい回から順にループ
        REPR(i,contest-1) {
            //ボーナスが出ていなければ、その回の一問分の得点をループで足していく
            if(!(x&(1<<i))) {
                //score>=goalとなるまで、また、その回の問題数が
                int tmp=theNumberOfProblems[i];//ボーナスで不十分の場合使いまわす可能性があるのでtmpを使う
                while(tmp) {
                    //
                    score += i+1;
                    tmp--;
                    cnt++;
                    if(score >= goal) {
                        ans=min(ans,cnt);
                        break;
                    }
                }
                break;
            }
        }
    }
        cout << ans << endl;
    //score = ボーナス + ボーナス取得回の得点 + ボーナス非取得回の得点
}