#include <bits/stdc++.h>

#define PI 3.14159265359
#define rep(i,a,n) for(int i=a;i<(int)n;++i)
#define SZ(x) ((int)(x).size())	//size() unsigned -> int
#define descSort(a) sort(a.begin(),a.end(),std::greater<int>())
using namespace std;
typedef long long ll;
const ll INF = 1e9 + 7;

int main() {
    int load[5][5]={0};
    rep(i,0,3){
        int a,b;
        cin>>a>>b;
        a--;b--;
        load[a][b]=1;
        load[b][a]=1;
    }

    bool ok=false;
    rep(i,0,4){
        rep(j,0,2){
            if(load[i][j]==load[3-i][3-j])ok=true;
            else {ok=false;break;}
        }
    }
    cout<<(ok?"YES":"NO")<<endl;
    return 0;
}