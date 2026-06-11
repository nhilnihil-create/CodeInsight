#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define OUT(x) cout << (x) << endl;
#define ALL(v) v.begin(), v.end()
#define REP(i, n) for (int i=0; i<n; ++i)

int main() {
    int N, A, B;
    cin >> N >> A >> B;
    string ans;

    for(;;){
        if(A+1==B) {
            ans = "Borys";
            break;
        }
        A++;
        if(A+1==B) {
            ans = "Alice";
            break;
        }
        B--;
    }
    OUT(ans);
}