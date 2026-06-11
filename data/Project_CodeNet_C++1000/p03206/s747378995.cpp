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
    int d; cin >> d;
    string ans;
    switch(d){
        case 25 :
            ans="Christmas";
            break;
        case 24 :
            ans="Christmas Eve";
            break;
        case 23 :
            ans="Christmas Eve Eve";
            break;
        case 22 :
            ans="Christmas Eve Eve Eve";
            break;
    }
    cout << ans << endl;
return 0;
}
