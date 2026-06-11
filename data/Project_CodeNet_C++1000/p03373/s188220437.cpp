#include <bits/stdc++.h>
#define REP(i,n) for(ll i=0;i<(ll)(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=(ll)(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=(ll)(b);i--)
#define ALL(x) (x).begin(),(x).end() 
#define SIZE(x) ((ll)(x).size())
#define MAX(x) *max_element(ALL(x))
#define MIN(x) *min_element(ALL(x))
#define INF 1000000000000
using namespace std;
typedef long long ll;

int main() {
    int A, B, C, X, Y, a, b, c, temp, sum;

    cin >> A >> B >> C >> X >> Y;

    sum = 1000000000;

    for (int c = 0; c <= max(X, Y); c++){
        temp = C * 2 * c;

        if (c < X){
            temp += (X - c) * A;
        }

        if (c < Y){
            temp += (Y - c) * B;
        }
        

        if (sum >= temp){
            sum = temp;
        }
    }
    cout << sum << endl;
}