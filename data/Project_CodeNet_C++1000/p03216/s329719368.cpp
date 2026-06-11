#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define REP(i, n) for(int i = 0; i < (int)(n); ++i)
#define FOR(i, m, n) for(int i = (int)(m); i < (int)(n); ++i)


int main()
{
    int N, Q;
    cin >> N;
    string S;
    cin >> S;
    cin >> Q;


    REP(i, Q){
        int k;
        cin >> k;

        long long ans = 0;
        long long num_D = 0, num_M = 0, num_DM = 0;
        REP(i, N){
            if(i >= k){
                if(S[i-k] == 'D'){
                    --num_D;
                    num_DM -= num_M;
                }
                if(S[i-k] == 'M') --num_M;
            }
            if(S[i] == 'D') ++num_D;
            if(S[i] == 'M'){
                ++num_M;
                num_DM += num_D;
            }
            if(S[i] == 'C') ans += num_DM;
        }
        cout << ans << endl;
    }

    return 0;
}