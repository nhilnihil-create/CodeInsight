#include <bits/stdc++.h>
using namespace std;

int main() {
    /* 入力部分 */
    int N,M;
    cin >> N;
    vector<string> s(N);
    for(int i=0;i<N;i++) {
        cin >> s.at(i);
    }
    cin >> M;
    vector<string> t(M);
    for(int i=0;i<M;i++) {
        cin >> t.at(i);
    }
    
    /* 計算部分 */
    int buf1 = 0; // 
    int buf2 = 0; //
    for(int i=0;i<N;i++) {
        buf1 = 0;
        for(int j=0;j<N+M;j++) {
            if(j<N) {
                if (s.at(i) == s.at(j)) {
                    buf1++;
                }
                //青のカード探索
            }else{
                if (s.at(i) == t.at(j-N)) {
                    buf1--;
                }
                //赤のカード探索
            }
        }
        buf2 = max(buf2,buf1);
    }
    cout << buf2 << endl;
}