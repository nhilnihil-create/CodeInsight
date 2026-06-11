#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)
const long long INF = 1<<29;
int N,A,B,C;
vector<int> l;

int dfs(int i,int a,int b,int c){
    if(i==N){
        if(!a||!b||!c) return INF;
        else return abs(A-a) + abs(B-b) + abs(C-c);
    }
    int res = dfs(i+1,a,b,c);

    res = min(res,dfs(i+1,a+l[i],b,c) + (a?10:0));
    res = min(res,dfs(i+1,a,b+l[i],c) + (b?10:0));
    res = min(res,dfs(i+1,a,b,c+l[i]) + (c?10:0));

    return res;
}

int main(){
    cin >> N >> A >> B >> C;
    l.resize(N);
    rep(i,N){
        cin >> l[i];
    }
    cout << dfs(0,0,0,0) << endl;
    return 0;
}