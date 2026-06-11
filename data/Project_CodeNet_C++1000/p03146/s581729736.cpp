#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<n; i++)
#define PI 3.14159265359
#define INF 1000100100
#define MOD 1000000007
#define all(x) (x).begin(),(x).end()
typedef long long ll;
#define P pair<ll,ll>
#define PP pair<P,P>
using namespace std;

int main(){
    int s; cin >> s;
    map<int,int> num;
    int i=1;
    for(;;){
        if(num[s]){
            cout << i << endl;
            return 0;
        }
        num[s]++;
        if(s%2==0) s/=2;
        else s=s*3+1;
        i++;
    }
return 0;
}
