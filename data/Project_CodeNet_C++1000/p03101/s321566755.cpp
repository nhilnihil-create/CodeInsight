#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<n; i++)
#define PI 3.14159265359
#define INF 1000100100
#define all(x) (x).begin(),(x).end()
typedef long long ll;
#define P pair<ll, ll>
#define PP pair<P,P>
using namespace std;

int main(){
    int h,w; cin >> h >> w;
    int a,b; cin >> a >> b;
    cout << h*w-((a*w)+(h-a)*b) << endl;
return 0;
}
