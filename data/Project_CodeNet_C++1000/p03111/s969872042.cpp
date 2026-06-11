#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int INF=pow(10,9);
int n,A,B,C;

int dfs(int i, int a, int b, int c, vector<int> &l){
    if(i == n){
        int calc;
        if(a>0 && b>0 && c>0){
            calc = abs(A-a) + abs(B-b) + abs(C-c) - 30;
            return calc;
        }
        else{
            return INF;
        }
    }
    else{
        int p,q,r,s;
        p = dfs(i+1, a+l.at(i), b, c, l)+10;
        q = dfs(i+1, a, b+l.at(i), c, l)+10;
        r = dfs(i+1, a, b, c+l.at(i), l)+10;
        s = dfs(i+1, a, b, c, l);
        return min(min(p,q), min(r,s));
    }
}

int main(){
    cin >> n >> A>> B >> C;
    vector<int> l(n);
    for(int i=0; i<n; i++){
        int k;
        cin >> k;
        l.at(i) = k;
    }
    int ans;
    ans = dfs(0, 0, 0, 0, l);
    cout << ans << endl;
}