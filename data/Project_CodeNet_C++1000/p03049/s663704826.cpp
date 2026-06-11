#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
using ll =  long long ;
using P = pair<int,int> ;
const int INF = 1e9;
const int MOD = 1000000007;

int main(){
    int n;
    cin >> n;
    vector<string> s(n);
    rep(i,n) cin >> s[i];
    int A = 0,B = 0;
    int AB = 0;
    bool ok = false;
    rep(i,n){
        rep(j,s[i].size()-1){
            if(s[i][j] == 'A' && s[i][j+1] == 'B'){
                ++AB;
            }
        }

        if(s[i][0] == 'B' && s[i].back() == 'A'){
            ++A;++B;
        }else if(s[i][0] == 'B'){
            ++B;ok = true;
        }else if(s[i].back() == 'A'){
            ++A;ok = true;
        }
    }
    if(ok) cout << AB + min(A,B) << endl;
    else cout << AB + (min(A,B)==0 ? 0 : min(A,B)-1) << endl;
    return 0;
}