#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> l_l;
typedef pair<int, int> i_i;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))

const ll mod = 1000000007;

int main() {
    string S, ans;
    cin >> S;

    int N = S.length();
    vector<int> array(N);

    rep(i, N){
        int froma;
        froma = S[i] - 'a';
        array[i] = froma;
    }
    
    ans = "";
    for(int i = 0; i < 26; i++){
        if(find(array.begin(), array.end(), i) == array.end()){
            array.push_back(i);
            for(int n: array){
                ans += 'a' + n;
            }
            cout << ans << endl;
            return 0;
        }
    }
    
    for(int i = N - 2; i >= 0; i--){
        for(int j = array[i] + 1; j < 26; j++){

            bool inArray = false;
            rep(k, i){
                if(array[k] == j){
                    inArray = true;
                }
            }
            if(!inArray){
                rep(k, i){
                    ans += 'a' + array[k];
                }
                ans += 'a' + j;
                cout << ans << endl;
                return 0;
            }
        }
    }
    cout << -1 << endl;

    
    return 0;
}
