#include <iostream>
#include <string.h>
#include <stdio.h>
#include <map>
#include <vector>
#include <math.h>
#include <algorithm>
#include <queue>
#include <set>
#include <tuple>
using namespace std;

#define rep(i,a) for(int i=0; i<a; i++)
#define rrep(i,a) for(int i=a; i>=0; i--)
#define rep1(i,a) for(int i=1; i<=a; i++)
#define cout1(a) cout << a << endl;
#define cout2(a,b) cout << a << " " << b << endl;
#define cout3(a,b,c) cout << a << " " << b << " " << c << endl;
#define cout4(a,b,c,d) cout << a << " " << b << " " << c << " " << d << endl;
#define mem(a,n) memset( a, n, sizeof(a))
#define all(a) a.begin(),a.end()

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef vector<int> V;
typedef vector<V> VV;
typedef vector<VV> VVV;
const int INF = 1e9;
const int MOD = 1e9+7;
const ll LLINF = 1e18;
static const double pi = 3.141592653589793;

int N, K, Q;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    cin>>N>>K>>Q;
    int seq[N+9];
    set<int> nums;
    rep(i,N) cin>>seq[i], nums.insert(seq[i]);
    
    int mn=INF;
    for(auto x:nums){
        vector<int> data1;
        for(int i=0;i<N;i++){
            vector<int> data2;
            while(seq[i]>=x&&i<N){
                data2.push_back(seq[i++]);
            }
            int len = data2.size();
            if(len>=K){
                sort(all(data2));
                data1.insert(data1.end(),data2.begin(),data2.begin()+(len-K+1));
            }
        }
        if(data1.size()>=Q){
            sort(all(data1));
            int n = data1[Q-1];
            if(mn>n-x) mn=n-x;
        }
    }
    cout1(mn);
}