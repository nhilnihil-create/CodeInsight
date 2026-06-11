#include <bits/stdc++.h>
#define REP(i,n) for(ll i=0;i<(ll)(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=(ll)(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=(ll)(b);i--)
#define ALL(x) (x).begin(),(x).end() 
#define SIZE(x) ((ll)(x).size())
#define MAX(x) *max_element(ALL(x))
#define MIN(x) *min_element(ALL(x))
#define INF 1000000000
using namespace std;
typedef long long ll;

int ctoi(const char c){
  switch(c){
    case '0': return 0;
    case '1': return 1;
    case '2': return 2;
    case '3': return 3;
    case '4': return 4;
    case '5': return 5;
    case '6': return 6;
    case '7': return 7;
    case '8': return 8;
    case '9': return 9;
    default : return -1;
  }
}

int main() {
    string S;
    cin >> S;

    int A[4];
    REP(i, 4){
        A[i] = ctoi(S[i]);
    }
    

    int res = 0;
    for (int bit = 0; bit < (1<<4); ++bit) {
        res = A[0];
        FOR(i, 1, 3) {
            if (bit & (1<<i)) {
                res += int(A[i]);
            }
            else{
                res -= int(A[i]);
            }
        }

        if(res == 7){
            cout << A[0];
            FOR(j, 1, 3){
                if (bit & (1<<j)){
                    cout << '+';
                }
                else{
                    cout << '-';
                }
                cout << A[j];
            }
            cout << "=7" << endl;
            break;
        }
    }
}