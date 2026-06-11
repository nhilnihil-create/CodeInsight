#include <bits/stdc++.h>
using namespace std;
#define pp pair<int,int>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define ll long long
#define ld long double
#define all(a) (a).begin(),(a).end()
#define mk make_pair
ll MOD=1000000007;
int inf=1000001000;
ll INF=100000000000000000;

int main() {
    int n;
    cin >> n;
    int l=1,r=n;
    vector<int> a(n),b(0);
    rep(i,n) {
        cin >> a.at(i);
        if(i!=0){
            if (a.at(i)<=a.at(i-1)) b.push_back(a.at(i));
        }
    }
    while(l!=r){
        int mid=(l+r)/2;
        map<int,int> m;
        bool t=false;
        rep(i,b.size()){
        while(!m.empty() && m.rbegin()->first > b[i])
			m.erase(prev(m.end()));

		int x = b[i];
		m[x]++;
		if(mid == 1) t=true;
        if (t) break;
		while(m[x] == mid) {
			m.erase(m.find(x));
			x--;
			m[x]++;
			if(x <= 0) {t=true;break;}
		}
		if(x <= 0) t=true;
	}
        if (t) l=mid+1;
        else r=mid;
    }
    cout << l << endl;
}
