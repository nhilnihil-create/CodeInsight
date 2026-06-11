#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
#include<list>
#include<set>
#include<map>
#include<string>
#include<bits/stdc++.h>

/*define*/
using namespace std;
#define rep(i, n) for(int i=0; i<n; ++i)
typedef long long ll;
typedef pair<int, int> P;
static const int max_n = 200000, max_m = 200000;
static const int  INF = 10000000;
vector<int> G[max_n];
int Color[max_n];
int ci;
int D;
int T;
string ans = "YES";
map<int, int> m;


int main(){
    int N, M;
    cin >> N;
    for(int i=0; i<N; i++){
        cin >> D;
        ++m[D];
    }
    cin >> M;
    rep(i, M){
        cin >> T;
        if(m[T]==0){
            ans = "NO";
            break;
        }
        --m[T];
    }
    cout << ans;
    return 0;
}