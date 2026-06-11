#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
#define REP(i, n) for(int i=0; i<n; i++)
#define REPi(i, a, b) for(int i=int(a); i<int(b); i++)
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
const ll MOD = 1e9+7;

int main(){
    int N;
    cin >> N;
    string S;
    cin >> S;
    int Q;
    cin >> Q;

    REP(q, Q){
        int k;
        cin >> k;

        int d = 0;
        int m = 0;
        ll num = 0;
        ll ans = 0;
        REP(i,N){
            char c = S[i];
            if(c == 'D'){
                d++;    
            }
            else if(c == 'M'){
                m++;
                num += d; 
            }
            else if(c == 'C'){
                ans += num;
            }

            if(i >= k-1){
                char pc = S[i - k + 1];
                if(pc == 'D'){
                    d--;    
                    num -= m;
                }
                else if(pc == 'M'){
                    m--;
                    //num -= d; 
                }
                else if(pc == 'C'){
                    //ans += num;
                }
            }
        }

        cout << ans << endl;
    }

    return 0;
}
