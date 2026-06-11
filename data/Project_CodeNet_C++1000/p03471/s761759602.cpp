#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define REP(i, N) for (int i = 0; i < (int)(N); i++)

// chmax, chmin
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main() {
    int N, Y;
    cin >> N >> Y;
    
    int num = Y / 1000;
    
    int a,b,c;
    bool exist = false;
    for ( int ten = 0; ten <= num; ++ten){
        int rest = num - 10 * ten;
        int restnum = rest / 5;
        for ( int five = 0; five <= restnum; ++five){
            int rest2 = rest - 5 * five;
            int all = ten + five + rest2;
            if ( all == N ) {
                a = ten; b = five; c = rest2;
                exist = true;
                goto OUT;
            }
        }
    }
    OUT:
    
    if ( exist ){
        cout << a << " " << b << " " << c << endl;
    } else {
        cout << "-1 -1 -1 " << endl;
    }
    
    
    
    
    return 0;
}
