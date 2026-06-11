#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

// chmax, chmin
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main() {
    int N;
    string S;
    cin >> N;
    cin >> S;
    
    int ans = 0;
    for ( int i = 1; i < N; ++i){
        int ans_sub = 0;
        vector<int> used(26,0);
        for ( int j = 0; j < i; ++j){
            int x = S[j] - 'a';
            used[x] = 1;
        }
        for ( int k = i; k < N; ++k){
            int y = S[k] - 'a';
            if ( used[y] == 1 ){
                used[y] = 2;
            }
        }
        for ( int l = 0; l < 26; ++l){
            if ( used[l] == 2 ) ++ ans_sub;
        }
        chmax(ans,ans_sub);
        
        /*cout << "i " <<  i << endl;
        for ( auto x : used ){
            cout << x << " " ;
        }
        cout << endl;*/
    }
    
    cout << ans << endl;
    return 0;
}
