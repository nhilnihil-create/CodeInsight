#include <iostream>
#define REP(i,n) for(ll i=0;i<(ll)(n);i++)
using namespace std;
typedef long long ll;

int A, B, C, X, counter, total;

int main() {
    cin >> A;
    cin >> B;
    cin >> C;
    cin >> X;
  
    counter = 0;
    REP(a,A+1){
        REP(b,B+1){
            REP(c,C+1){
                total = 500*a + 100*b + 50*c;
                if (total == X) {
                    counter++;
                }
            }
        }
    }
    cout << counter << endl;
}