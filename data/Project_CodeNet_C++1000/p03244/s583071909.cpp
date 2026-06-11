#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

const int INF = 1e9;
const int MOD = 1e9+7;
const ll LINF = 1e18;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n) for(int i=0;i<(n);++i)
#define REPR(i,n) for(int i=n;i>=0;i--)
#define ALL(v) (v.begin(),v.end())
#define COUT(x) cout<<(x)<<endl

int even[100010];
int odd[100010];

int main(){
    int n,t;cin >> n;
    REP(i,n){
        cin >> t;
        if(i%2==0)odd[t]++;
        else even[t]++;
    }
    int odd1,odd2,odd_num1,odd_num2;
    int max1 = 0;
    REP(i,100010){
        if(max1<odd[i]){
            max1 = odd[i];
            odd_num1 = i;
        }
        odd1 = max1;
    }
    int max2 = 0;
    REP(i,100010){
        if(max2<odd[i]){
            if(i==odd_num1)continue;
            max2 = odd[i];
            odd_num2 = i;
        }
        odd2 = max2;
    }
    //odd1,odd2は個数,odd_num1,odd_num2はその数
    //evenも同様に
    int even1,even2,even_num1,even_num2;
    int max3 = 0;
    REP(i,100010){
        if(max3<even[i]){
            max3 = even[i];
            even_num1 = i;
        }
        even1 = max3;
    }
    int max4 = 0;
    REP(i,100009){
        if(max4<even[i]){
            if(i==even_num1)continue;
            max4 = even[i];
            even_num2 = i;
        }
        even2 = max4;
    }
    int ans = 0;
    //cout << odd1 << " " << odd2 << " " << even1 << " " << even2 << endl;
    
    if(odd_num1!=even_num1)ans = n-odd1-even1;
    else ans = min(n-(odd1+even2),n-(even1+odd2));
    COUT(ans);
    return 0;
}