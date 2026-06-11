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
    string s;
    cin>>s;
    int n=s.length();
    s='A'+s;
    bool maki=true;
    if(s[n]=='1')maki=false;
    if(s[1]=='0')maki=false;
    for(int i=1;i<n;i++){
    	if(s[i]!=s[n-i])maki=false;
    }
    if(!maki){
    	cout << -1<<endl;
    	return 0;
    }
    int m=n/2;
    vector<int> v;
    for(int i=2;i<=m;i++){
    	if(s[i]=='1')v.pb(i);
    }
    vector<pair<int,int> > ans;
    int index=1;
    for(auto& i:v){
    	for(int j=index;j<i;j++){
    		ans.push_back({j,i});
    	}
    	index=i;
    }
    for(int i=index;i<n;i++){
    	ans.push_back({i,n});
    }
    for(auto& i:ans){
    	cout <<i.first<< " " <<i.second <<endl;
    }

    return 0;
}
