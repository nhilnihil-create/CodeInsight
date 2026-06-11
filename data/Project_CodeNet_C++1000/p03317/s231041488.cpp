#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rrep(i, n) for (int i = 1; i < (n+1); ++i)
using namespace std;
using ll = long long;
const ll INF = +10010010000;

typedef pair<ll,ll> P;
const ll MO = 1000000007;

int main(){
    int n,k;
    cin >> n >> k;
    int mini;
    vector<int>a(n);
    rep(i,n){
        cin >>a[i];
        if(a[i]==1)mini = i;
    }
    if(n-k<=0){
        cout <<1 << endl;
        return 0;
    }else{
        int g = 1;
        while(n>k+(k-1)*(g-1)){
            ++g;
        }
        cout << g << endl;
        return 0;
    }
}