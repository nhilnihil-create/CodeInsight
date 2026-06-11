#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i = 0; i < (n); ++i)
#define ll long long
const ll mod = 1e9+7;
int inf = 1000000000; //10e9
 
bool isacgt(char c){
    return (
        c=='A' || c=='C' || c=='G' || c=='T'
    );
}

int main() {

    string s;
    cin >> s;
    int n = s.size();

    int len=0, ans=0;
    rep(i,n){
        if(isacgt(s[i])){
            len++;
        }else{
            len=0;
        }
        ans = max(len,ans);
    }

    cout << ans << endl;

    return 0;

}