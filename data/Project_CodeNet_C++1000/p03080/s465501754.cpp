#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long long int llint;
typedef pair<ll, ll> pa;
#define MM 1000000000
#define MOD MM+7
#define MAX 101000
#define MAP 110
#define initial_value -1
#define Pair pair<int,int>
#define chmax(a,b) (a<b ? a=b:0)
#define chmin(a,b) (a>b ? a=b:0)
#define INF (1 << 29) //536870912
int dx[4] = {-1,0,1,0};
int dy[4] = {0,-1,0,1};
int main(){
    int n; string s;
    cin >> n >> s;
    map<char,int> mp;
    for(int i = 0; i < n; i++){
        mp[s[i]]++;
    }
    if(mp['R'] > mp['B']) cout << "Yes" << endl;
    else cout << "No" << endl;
}

