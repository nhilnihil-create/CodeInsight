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
    int n;
    cin>>n;
    vector<pair<int,int> > v;
    int m=(n%2)?n:n+1;
    for(int i=1;i<=n;i++){
    	for(int j=i+1;j<=n;j++){
    		if(i+j!=m){
    			v.pb(make_pair(i,j));
    		}
    	}
    }
    cout << (v.size()) <<endl;
    for(auto i:v){
    	cout <<i.first<<" "<<i.second<<endl;
    }
    return 0;
}
