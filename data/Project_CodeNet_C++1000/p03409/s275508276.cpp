#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

pair<int,int> r[105],b[105];
bool used[105];

int main(){
  int n;
	cin >> n;
	rep(i,n){
		int x,y;
		cin >> x >> y;
		r[i] = make_pair(x,y);
	}
	rep(i,n){
		int x,y;
		cin >> x >> y;
		b[i] = make_pair(x,y);
	}
	sort(r,r+n); sort(b,b+n);
	int ans = 0;
	rep(i,n){
    int alternative=-1;
    int value=-1;
    rep(j,n){
      if(used[j])continue;
      if(r[j].first<b[i].first&&r[j].second<b[i].second){
        if(value<=r[j].second){
          alternative=j;
          value = r[j].second;
        }
      }
    }
    if(alternative==-1)continue;
    used[alternative]=1;
    ans++;
  }
	cout << ans << endl;
	return 0;
}
