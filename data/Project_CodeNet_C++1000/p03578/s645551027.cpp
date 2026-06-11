#include<bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define put(i) cout<<fixed<<i<<endl
using namespace std;
using ll = long long;

int main(){
    int n; cin >> n;
    map<int,int> d;
    rep(i,n){
        int tmp; cin >> tmp;
        d[tmp]++;
    }
    int m; cin >> m;
    map<int,int> t;
    rep(i,m){
        int tmp; cin >> tmp;
        t[tmp]++;
    }

    for(auto a:t){
        //cout << a.first << " " << a.second << " ";
        if(d[a.first] - a.second < 0){
            put("NO");
            return 0;
        }
    }
    //cout << endl;
    put("YES");
}