#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
typedef long long ll;
int main() {
    int N,Q;
    string Str;
    cin >> N >> Q >> Str;
    vector<int>S(N+1, 0);
    rep(i, 0, N){
        if(i+1<N && Str[i] == 'A' && Str[i+1] == 'C'){
            S[i+1] = S[i]+1;
        } else {
            S[i+1] = S[i];
        }
    }
    rep(i, 0, Q){
        int l,r;
        cin >> l >> r;
        l--;
        r--;
        cout << S[r] - S[l] << endl;
    }
    
    return 0;
}