#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll mod = 1e9+7;
#define rep(i,n) for(int i = 0; i < (n); ++i)

int main(){
    int n;
    cin >> n;
    int l = -1;
    int r = n;
    int idx;
    int male = 0;
    int female = 0;
    rep(i, 20) {
        if ( i == 0 ) {
            idx = 0;
        }
        else {
            idx = ( r + l ) / 2;
        }
        cout << idx << endl;
        cout.flush();
        string s;
        cin >> s;
        if ( s == "Vacant" ) {
            return 0;
        }
        else if ( s == "Male" ) {
            if ( i == 0 ) {
                male = idx % 2;
                female = ( idx % 2 ) ? 0 : 1;
                idx = ( r + l ) / 2;
            }
            else if ( male != idx % 2 ) {
                r = idx;
            }
            else {
                l = idx;
            }
        }
        else {
            if ( i == 0 ) {
                female = idx % 2;
                male = ( idx % 2 ) ? 0 : 1;
                idx = ( r + l ) / 2;
            }
            else if ( female != idx % 2 ) {
                r = idx;
            }
            else {
                l = idx;
            }
        }
    }
    return 0;
}
