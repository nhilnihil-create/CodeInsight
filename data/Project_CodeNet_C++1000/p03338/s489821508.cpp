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
    string s; cin >> s;
    int ans=0;
    rep(i,n-1){
        int tmp=0;
        rep(a,26){
            bool ok=false;
            rep(j,i+1){
                if(s[j]=='a'+a){
                    ok=true;
                    break;
                }
            }
            bool ok2=false;
            Rep(j,i+1,n){
                if(s[j]=='a'+a){
                    ok2=true;
                    break;
                }
            }
            if(ok && ok2) tmp++;
        }
        ans=max(ans,tmp);
    }

    cout << ans << endl;
    return 0;
}