#include <bits/stdc++.h>
#define be(v) (v).begin(),(v).end()
#define pb(q) push_back(q)
typedef long long ll;
using namespace std;
const ll mod=1000000007;
#define doublecout(a) cout<<fixed<<setprecision(10)<<a<<endl;

int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    int n,a,m=1;
    cin>>n;
    for(int i=0;i<n;i++){
    	cin>>a;
    	m*=((a&1)?1:2);
    }
    cout << pow(3,n)-m <<endl;
    return 0;
}

