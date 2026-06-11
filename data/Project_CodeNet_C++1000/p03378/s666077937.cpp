#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
#include<queue>
#include<map>
#include<string>
#define all(x) (x).begin(),(x).end()
#define print(x) cout << (x) << endl
typedef long long ll;
typedef long double ld;
const ll MOD = 1000000007;
const ll MOD2 = 998244353;
 
using namespace std;

int main(){
    int N, M, X;    cin >> N >> M >> X;
    int l = 0, r = 0;
    for(int i=0; i<M; i++){
        int a;  cin >> a;
        if(a < X)   l++;
        else    r++;
    }
    print(min(l,r));
}