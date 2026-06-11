#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)
typedef int64_t Int;

int N;
vector<int> A(200010);

int main(){
    cin >> N;
    rep(i,N) cin >> A[i];

    int l = 0, r = 0; Int ans = 0;
    bitset<22> bit(A[0]);

    while(l < N){
        while(true){
            if(r == N-1) break;

            int nr = r+1;
            bitset<22> cur_bit(A[nr]);
            if((bit | cur_bit) == (bit ^ cur_bit)){
                bit |= cur_bit;
            } else {
                break;
            }
            r++;
        }

        ans += r-l+1;

        bitset<22> bit_l(A[l]);
        bit ^= bit_l;

        l++;
    }   

    cout << ans << endl;
}