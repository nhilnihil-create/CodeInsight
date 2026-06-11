#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define db double
#define pii pair<int,int>
#define pli pair<ll,int>
#define pil pair<int,ll>
#define pll pair<ll,ll>
#define mat vector<vector<int>>
const int inf = 1 << 30;
const ll linf = 1e18;
const db EPS = 1e-7;
template<class T> void chmin(T& x, T y){if(x > y) x = y;}
template<class T> void chmax(T& x, T y){if(x < y) x = y;}

int N;
int A[2010];
int sum = 0;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    for(int i = 0; i < N; i++) cin >> A[i], sum += A[i];
    bitset<4000010> ok(0);
    ok[0] = 1;
    for(int i = 0; i < N; i++) ok |= ok << A[i];
    int mid = (sum + 1) / 2;
    for(int i = (sum + 1) / 2; i <= 2000 * 2000; i++){
        if(ok[i]){
            cout << i << endl;
            return 0;
        }
    }
}