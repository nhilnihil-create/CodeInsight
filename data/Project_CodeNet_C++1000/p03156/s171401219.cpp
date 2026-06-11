#include <bits/stdc++.h>
using namespace std;
#define ALL(a) (a).begin(),(a).end()
#define rALL(a) (a).rbegin(),(a).rend()
typedef pair<int, int> Pint;
typedef pair<int64_t, int64_t> Pll;


int main() {
    int N, A, B, P1 = 0, P2 = 0, P3 = 0;
    cin >> N >> A >> B;
    for (int i = 0; i < N; i++){
        int a;
        cin >> a;
        if (a >= B + 1){
            P3++;
        }
        else if(a >= A + 1){
            P2++;
        }
        else {
            P1++;
        }
    }
    cout << min({P1, P2, P3}) << endl;

}

