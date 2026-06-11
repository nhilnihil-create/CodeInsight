#include <bits/stdc++.h>

#define rep(X,N) for(ll X = 0LL; X < (N); X++)
#define ALL(V) (V).begin(),(V).end()
#define endl "\n"

using namespace std;
typedef long long ll;

const double PI = 3.1415926535897932384626;
const ll MODN = 1000000007;
const ll MODN2 = 998244353;
const double EPS = 1e-10;

int main(){

    string s;
    cin >> s;

    int size = s.size();
    int count = 0;

    vector<int> xcount;
    vector<char> notx;

    rep(i, size){
        if(s[i] == 'x'){
            count++;
        }else{
            notx.push_back(s[i]);
            
            xcount.push_back(count);
            count = 0;
        }
    }

    xcount.push_back(count);

    int ans = 0;

    rep(i, xcount.size() / 2){
        ans += max(xcount[i], xcount[xcount.size() - 1 - i]) - min(xcount[i], xcount[xcount.size() - 1 - i]);
    }

    rep(i, notx.size()){
        if(notx[i] != notx[notx.size() - 1 - i]){
            ans = -1;
            break;
        }
    }

    cout << ans << endl;

    return 0;
}
