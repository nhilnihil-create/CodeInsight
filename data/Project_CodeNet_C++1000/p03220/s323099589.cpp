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
    int n; cin >> n;
    int t,a; cin>> t >> a;
    double ans=INF;
    int Ans;
    rep(i,n){
        int h; cin >> h;
        double tem=t-h*0.006;
        double now=abs(a-tem);
        if(ans>now){
            Ans=i+1;
            ans=now;
        }
    }
    cout << Ans << endl;
    return 0;
}
