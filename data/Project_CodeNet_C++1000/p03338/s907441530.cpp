#include <bits/stdc++.h>
using namespace std;
#define fv            first
#define sv            second
#define ll            long long
#define pb            push_back
#define mp            make_pair
#define pll           pair<ll,ll>
#define pii           pair<int,int>
#define READ(x)       freopen(x,"r",stdin)
#define WRITE(x)      freopen(x,"w",stdout)
#define isWorking()   cout<<"Wroking"<<endl
#define all(x)        (x).begin(),(x).end()
#define allr(x)       (x).rbegin(),(x).rend()
#define PRINT(ok)     cout<<(ok? "YES":"NO")<<endl
#define DoublePrint(x,a) cout<<fixed<<setprecision(x)<<a<<endl
#define Fast_Input    ios_base :: sync_with_stdio(0),cin.tie(0);

const ll mod= 1e9+7,INF=1e8,mx= 1e6+5,mn=100;
int testCase=1,cas=0;

int Cnt[200],Taken[200];

int main() {
    Fast_Input

    //cin >> testCase;
    while(testCase--) {
        int n; cin >> n;
       string str; cin >> str;

       int ans = 0;

       for(int i=0; i<str.size(); i++){
            Cnt[ str[i] ] = 1;

            int cnt = 0;

            for(int j=i+1; j<str.size(); j++){
                if(Cnt[ str[j] ] && !Taken[ str[j] ]){
                    cnt ++;
                    Taken [ str[j] ] = 1;
                }
            }

            ans = max(ans,cnt);
            memset(Taken,0,sizeof Taken);
       }

       cout << ans << endl;
    }
    return 0;
}
