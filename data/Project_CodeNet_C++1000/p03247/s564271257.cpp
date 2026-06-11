#include<bits/stdc++.h>
using namespace std;
#define fs first
#define sc second
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define ALL(A) A.begin(),A.end()
#define RALL(A) A.rbegin(),A.rend()
typedef long long LL;
typedef pair<LL,LL> P;
const LL mod=1000000007;
const LL LINF=1LL<<62;
const int INF=1<<20;


int main(){
    int n;cin >> n;
    vector<P> v;
    for (int i = 0; i < n; i++) {
        LL x,y;
        cin >> x >> y;
        v.pb(P(x+y,x-y));
    }
    for (int i = 0; i < n-1; i++) {
        if(abs(v[i+1].fs)%2!=abs(v[i].fs)%2){
            puts("-1");
            return 0;
        }
    }
    int m;
    vector<LL> d;
    if(v[0].fs%2){
        m = 31;
        cout << m << endl;
        for (int i = 0; i < m; i++) {
            cout << (1LL<<i) << " ";
            d.pb(1LL<<i);
        }
        puts("");
    }
    else{
        m = 32;
        cout << m << endl;
        cout << 1 << " ";
        d.pb(1);
        for (int i = 0; i < m-1; i++) {
            cout << (1LL<<i) << " ";
            d.pb(1LL<<i);
        }
        puts("");
    }
    for (int i = 0; i < n; i++) {
        vector<bool> x(m),y(m);
        LL s = abs(v[i].fs),t=abs(v[i].sc);
        LL ssum=0,tsum=0;
        for (int j = m-1; j >= 0; j--) {
            if(ssum - s <= 0){
                ssum += d[j];
                x[j] = true;
            }
            else{
                ssum -= d[j];
                x[j] = false;
            }
            if(tsum - t <= 0){
                tsum += d[j];
                y[j] = true;
            }
            else{
                tsum -= d[j];
                y[j] =false;
            }
        }
        LL a=0,b=0;
        for (int j = 0; j < m; j++) {
            if(v[i].fs<0) x[j]=x[j]^1;
            if(v[i].sc<0) y[j]=y[j]^1;
            if(x[j]&&y[j]) cout << "R";
            else if(x[j]&&!y[j]) cout << "U";
            else if(!x[j]&&y[j]) cout << "D"; 
            else cout << "L";
            a+=(x[j]?1:-1)*d[j];
            b+=(y[j]?1:-1)*d[j];
        }
        puts("");
    }
    return 0;
}
