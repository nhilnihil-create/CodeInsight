#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
ll n,m;
vector<int> v[100000];
int c[100000];
void f(int x, int y){
    if(c[x]==0){
        c[x]=y;
        for(int i=0;i<v[x].size();i++){
            f(v[x][i], 3-y);
        }
    }else if(c[x]!=y){
        c[x]=-1;
    }
}
int main(void){
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        a--;
        b--;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    fill(c, c+n, 0);
    f(0, 1);
    ll d=0;
    for(int i=0;i<n;i++){
        if(c[i]==-1){
            d=-1;
            break;
        }else if(c[i]==1){
            d++;
        }
    }
    ll ans=-m;
    if(d==-1){
        ans+=n*(n-1)/2;
    }else{
        ans+=d*(n-d);
    }
    cout << ans << endl;
}
