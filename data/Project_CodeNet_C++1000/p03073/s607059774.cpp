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

char Change(char x){
    if(x=='1') return '0';
    return '1';
}

int main() {
    Fast_Input

    while(testCase--) {
        string str; cin >> str;

        string str2 = str;

        int n = str.size() , ans1 = 0, ans2 = 0;

        for(int i=1; i<n; i++){
            if(str[i] == str[i-1]){
                str[i] = Change(str[i-1]);
                ans1 ++;
            }
        }

        str2[0] = Change(str2[0]);
        ans2 ++;

        for(int i=1; i<n; i++){
            if(str2[i] == str2[i-1]){
                str2[i] = Change(str2[i-1]);
                ans2 ++;
            }
        }

        cout << min(ans1,ans2) << endl;
    }
    return 0;
}
