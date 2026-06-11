#include <iostream>
//解答解法
using namespace std;
int main(){
    int N;
    cin >> N;
    int res = 1e9;
    for(int i = 0; i <= N ; i++){//i円を6^kのみで引き出し、残りを9^lのみで引き出す
        int cnt = 0;
        int t = i;
        while(t > 0){//6進数の各桁を足す(tを6^kのみで引き出したときの最小回数)
            cnt += t % 6;
            t /= 6;
        }
        int s = N - i;
        while(s > 0){//9進数ver
            cnt += s % 9;
            s /= 9;
        }
        res = min(res, cnt);
    }
    cout << res << endl;
}
