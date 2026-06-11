#include <bits/stdc++.h>
using namespace std;

const int INF = 1e+6;

int N,A,B,C;
vector<int> l;

// x これまでに何本使ったか
int dfs(int x, int a, int b, int c ){
    if ( x == N ) {
        if ( min(a,min(b,c)) == 0 ) return INF;
        else return abs(a-A) + abs(b-B) + abs(c-C) - 30;
    }
    int ans0 = dfs(x+1,a,b,c);
    int ans1 = dfs(x+1,a+l[x],b,c) + 10;
    int ans2 = dfs(x+1,a,b+l[x],c) + 10;
    int ans3 = dfs(x+1,a,b,c+l[x]) + 10;
    return min(min(ans0,ans1),min(ans2,ans3));
}

int main() {
    cin >> N >> A >> B >> C;
    l.resize(N);
    for ( int i = 0; i < N; ++i){
        cin >> l[i];
    }
    
    cout << dfs(0,0,0,0) << endl;
    return 0;
}
