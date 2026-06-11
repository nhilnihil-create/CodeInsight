#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
typedef long long ll;
int main() {
    int N ;
    cin >> N;
    vector<ll> CC(5,0);
    rep(i, 0, N){
        string S;
        cin >> S;
        switch (S[0]) {
            case 'M':
                CC[0]++;
                break;
            case 'A':
                CC[1]++;
                break;
            case 'R':
                CC[2]++;
                break;
            case 'C':
                CC[3]++;
                break;
            case 'H':
                CC[4]++;
                break;
            default:
                break;
        }
    }
    ll ans = 0;
    rep(i, 0, 5){
        rep(j, i+1, 5){
            rep(k, j+1, 5){
                ans += CC[i]*CC[j]*CC[k];
            }
        }
    }
    
    cout << ans << endl;
    return 0;
}
