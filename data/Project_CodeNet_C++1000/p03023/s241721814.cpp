#include <bits/stdc++.h>

using namespace std;

const long long MOD = 1000000007LL;
long long GCD(long long a, long long b){return b == 0 ? a : GCD(b, a % b);}


/*int dsu[100001], ranks[100001];
int find(int node){
    if(dsu[node] == node) return node;
    return dsu[node] = find(dsu[node]);
}
void combine(int a, int b){
    a = find(a); b = find(b);
    if(a == b) return;
    if(ranks[a] < ranks[b]){
        dsu[a] = b;
    } else if(ranks[b] < ranks[a]){
        dsu[b] = a;
    } else {
        dsu[a] = b; ranks[b]++;
    }
}*/

int main(){

    cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n; cin >> n;

    cout << 180 * (n - 2);


    return 0;
}
