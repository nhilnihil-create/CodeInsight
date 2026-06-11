#include<bits/stdc++.h>
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define int long long
#define vec(a,n) vector<int> (a)((n))
#define Vec(a,n) vector<string> (a)((n))
#define P pair<int,int>
#define PQ(n) priority_queue<P,vector<P>,greater<P>> (n)
#define pq(n) priority_queue<int> (n)
using namespace std;

signed main(){
    int n,p,ans=1;
    cin >> n >> p;
    if(n==1){
        cout << p << endl;
        return 0;
    }
    int temp = p;
    for(int i=2; p>=i*i;i++){
        int tmp=temp;
        int x = 1,cnt=0;

        while(x == 1){
            if(tmp%i!=0){
                x=0;
            }
            else{
                cnt++;
                tmp /=i;
            }
        }
        int temp1 = 1;
        REP(j,cnt/n){
            temp1 *= i;
        }
        if(temp1 != 1){
            ans *= temp1;
            REP(k,n){
                temp /= temp1;
            }
        }

    }
    cout << ans << endl;
    return 0;
}
