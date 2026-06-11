#include<iostream>
#include<algorithm>
#include<string>
#include<map>
#include<vector>
#include<set>
#include<iomanip>
#include<cmath>
using namespace std;
typedef long long ll;
typedef long long int llint;
typedef pair<ll, ll> pa;
#define MM 1000000000
#define MOD MM+7
#define MAX 101000
#define MAP 110
#define initial_value -1
#define MAX_T 1001
#define Pair pair<int,int>
#define chmax(a,b) (a<b ? a=b:0)
#define chmin(a,b) (a>b ? a=b:0)
#define INF (1 << 29) //536870912
const long double PI = acos(-1);
const ll DEP = 1e18;
int dx[4] = {-1,0,1,0};
int dy[4] = {0,-1,0,1};
int N,Q;
string s;
char t[200002],d[200002];
int binary_search(int x){
    for(int i = 0; i < Q; i++){
        if(s[x] == t[i]){
            if(d[i] == 'R') x++;
            else x--;
        }
        if(x == -1) return -1;
        if(x == N) return 1;
    }
    return 0;
}
int main(){
    cin >> N >> Q;
    cin >> s;
    vector<int> go(N+1,-2);
    for(int i = 0; i < Q; i++){
        cin >> t[i] >> d[i];
    }
    int l = -1;
    int r = N;
    int mid;
    while(l < r -1){
        mid = (l+r)/2;
        if(binary_search(mid) == -1) l = mid;
        else r = mid;
    }
    int z = l;
    l = -1; 
    r = N;
    while(l < r-1){
        mid = (l+r)/2;
        if(binary_search(mid) == 1) r = mid;
        else l = mid;
    }
    int zz = r;
    cout << zz - z - 1 << endl;
}

