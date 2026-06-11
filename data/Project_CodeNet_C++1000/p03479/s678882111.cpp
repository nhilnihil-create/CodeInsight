#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
#include<utility>
#include<cstdio>
#include<set>
#include<string>
#include<map>
#include<queue>
#include<stack>
#include <bitset>
using namespace std;
const int mod=1e9+7;
#define rep(i,n) for(int i=0;i<n;i++)
#define rep2(i,x,n) for (int i= x;i<n;i++)
#define all(v) v.begin(), v.end()
#define nepe(v) next_permutation(all(v))
using ll = long long;
using vi = vector<int>; 
using vvi = vector<vi>;

typedef pair<int,int> P;
string s;
int k;
ll INF = 10000000000000000;

int main(){
    ll X,Y;
    cin >>X>>Y;
    int ans=0;
    while(X<=Y){
        X *=2;
        ans++;
    }
    cout <<ans<<endl;
}