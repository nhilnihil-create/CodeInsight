#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e5+15;

vector<int> ret[N];
void solve(){
    int n;
    scanf("%d",&n);
    int k;
    for(k = 1;(k*(k-1))/2<n;++k);
    
    if( (k*(k-1)) != n*2){
        cout<<"No\n";
    } else {
        int pos = 1;
        for(int x = 1;x<=k;++x){
            for(int y = x+1;y<=k;++y){
                ret[x].push_back(pos);
                ret[y].push_back(pos++);
            }
        }
        printf("Yes\n%d\n",k);
        for(int i=1;i<=k;++i){
            printf("%d ", (int)ret[i].size());

            for(int v : ret[i]){
                printf("%d ", v);
            }
            putchar('\n');
        }
    }
}
int main(){
    //freopen("input.txt","r",stdin);
    solve();
}
