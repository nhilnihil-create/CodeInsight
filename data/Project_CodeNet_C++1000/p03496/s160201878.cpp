#include <bits/stdc++.h>
using namespace std;
#define REP(i,a) for(int i = 0; i < (a); i++)
#define ALL(a) (a).begin(),(a).end()
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1e9;
const long long LINF = 1e18;
const long long MOD = 1e9 + 7;

signed main(){
    int n;
    cin >> n;
    vector<P> vec;
    int a[n];
    REP(i,n){
        cin >> a[i];
        vec.emplace_back(a[i], i);
    }
    sort(ALL(vec));
    cout << n * 2 - 1 << endl;
    if(vec[n - 1].first >= abs(vec[0].first)){
        for(int i = 1; i <= n; i++){
            cout << vec[n - 1].second + 1 << " " << i << endl;
        }
        for(int i = 1; i < n; i++){
            cout << i << " " << i + 1 << endl;
        }
    }else{
        for(int i = 1; i <= n; i++){
            cout << vec[0].second + 1 << " " << i << endl;
        }
        for(int i = n; i > 1; i--){
            cout << i << " " << i - 1 << endl;
        }
    }
    return 0;
}