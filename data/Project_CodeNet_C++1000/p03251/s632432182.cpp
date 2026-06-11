#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<n; i++)
#define PI 3.14159265359
#define INF 1000100100
#define MOD 1000000007
#define all(x) (x).begin(),(x).end()
typedef long long ll;
#define P pair<int, int>
#define PP pair<P,int>
#define T tuple<int,int,int> 
using namespace std;

int main(){
    int n,m,x,y; cin >> n >> m >> x >> y;
    vector<int> xx(n),yy(m);
    rep(i,n) cin >> xx[i];
    rep(i,m) cin >> yy[i];
    sort(all(xx));
    sort(all(yy));

    for(int z=x+1; z<=y; z++){
            if(z>xx[n-1] && z<=yy[0]){
                cout << "No War" << endl;
                return 0;
            }
    }

    cout << "War" << endl;
    return 0;
}
