#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
#include<queue>
#include<map>
#define all(x) (x).begin(),(x).end()
#define print(x) cout << (x) << endl
typedef long long ll;
const ll MOD = 1000000007;
const ll MOD2 = 998244353;
 
using namespace std;

int main(){
    int N, H;   cin >> N >> H;
    vector<int> a(N), b(N);
    for(int i=0; i<N; i++)  cin >> a[i] >> b[i];
    sort(all(a),greater<int>());
    sort(all(b),greater<int>());
    int maxa = a[0], cnt = 0;
    for(int i=0; i<N; i++){
        if(b[i] > maxa){
            cnt++;
            H -= b[i];
        }
        if(H <= 0){print(cnt);return 0;}
    }
    cnt += (H - 1) / maxa;
    cnt++;
    print(cnt);
}