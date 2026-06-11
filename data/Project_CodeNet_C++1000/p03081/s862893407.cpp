#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define REP(i, n) for(int i = 0; i < (int)(n); ++i)
#define FOR(i, m, n) for(int i = (int)(m); i < (int)(n); ++i)


int main()
{
    int N, Q;
    cin >> N >> Q;
    string s;
    cin >> s;
    vector<char> t(Q), d(Q);
    REP(i, Q) cin >> t[i] >> d[i];

    int ans_left, ans_right;

    // 左にギリギリ落ちないものを二分探索
    int left = 0, right = N; // 左に全部落ちる場合に備えて N から
    while(left < right){
        int mid = (left+right)/2;
        int pos = mid;
        REP(i, Q){
            if(t[i] == s[pos]){
                if(d[i] == 'L') --pos;
                if(d[i] == 'R') ++pos;
                if(pos < 0){
                    left = mid+1;
                    break;
                }
                if(pos >= N) break;
            }
        }
        if(pos >= 0) right = mid;
        // cout << "left: " <<  left << " " << right << endl;
    }
    ans_left = left;

    left = -1, right = N-1; // 右に全部落ちる場合に備えて -1 から
    // 右にギリギリ落ちないものを二分探索
    while(left < right){
        int mid = (left+right+1)/2;
        int pos = mid;
        REP(i, Q){
            if(t[i] == s[pos]){
                if(d[i] == 'L') --pos;
                if(d[i] == 'R') ++pos;
                if(pos < 0) break;
                if(pos >= N){
                    right = mid-1;
                    break;
                }
            }
        }
        if(pos < N) left = mid;
        // cout << "right: " << left << " " << right << endl;
    }
    ans_right = right;

    cout << ans_right-ans_left+1 << endl;


    return 0;
}