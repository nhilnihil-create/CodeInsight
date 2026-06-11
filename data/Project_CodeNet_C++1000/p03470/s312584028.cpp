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
    int N;  cin >> N;
    vector<int> v(N);
    for(int i=0; i<N; i++)  cin >> v[i];
    sort(all(v));
    int cnt = 0, tmp = 0;
    for(int i=0; i<N; i++){
        if(v[i] > tmp){cnt++; tmp=v[i];}
    }
    print(cnt);
}