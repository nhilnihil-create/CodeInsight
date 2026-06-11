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
    vector<int> aa(3);
    cin>> aa[0] >> aa[1] >> aa[2];
    sort(all(aa));
    reverse(all(aa));
    cout << aa[0]*10+aa[1]+aa[2];
    return 0;
}
