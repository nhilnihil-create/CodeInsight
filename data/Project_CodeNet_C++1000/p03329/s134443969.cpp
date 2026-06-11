#include <bits/stdc++.h>
#define Rep(i,j,n) for(int i=j; i<n; i++)
#define rep(i,n) for(int i=0; i<n; i++)
#define PI 3.14159265359
#define INF 1000100100//000000000
#define MOD 1000000007
#define all(x) (x).begin(),(x).end()
typedef long long ll;
#define P pair<int, int>
#define PP pair<P,P>
#define T tuple<int,int,int> 
using namespace std;

int main(){
    int n; cin >> n;
    int ans=INF;
    queue<P> q;
    q.emplace(n,0);
    while(!q.empty()){
        int f=q.front().first;
        int c=q.front().second;
        q.pop();
        if(f<=5){
            ans=min(ans,c+f);
            continue;
        }
        int now=1;
        int now2=1;
        while(now*9<=f) now*=9;
        while(now2*6<=f) now2*=6;
        q.emplace(f-now,c+1);
        q.emplace(f-now2,c+1);
    }
    cout << ans << endl;
    return 0;
}
