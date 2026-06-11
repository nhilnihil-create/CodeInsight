#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);++i)
#define ALL(A) A.begin(), A.end()

using namespace std;

typedef long long ll;
typedef pair<int, int> P;
typedef pair<char,char> C;

vector<C> v;
int N, Q;
string s;

int check(int pos){
	rep (i, Q){
		if (v[i].first == s[pos]){
			if (v[i].second == 'L'){
				--pos;
			}else{
				++pos;
			} // end if
		} // end if
		if (pos < 0) return -1;
		if (pos >= N) return 1;
	} // end rep
	return 0;
}

int left_border(void){
	int l = -1;
	int r = N;
	while(r - l > 1){
		int mid = (l + r) / 2;
		if (check(mid) != -1){
			r = mid;
		}else{
			l = mid;
		} // end if
	} // end while
	return r;
}

int right_border(void){
	int l = -1;
	int r = N;
	while(r - l > 1){
		int mid = (l + r) / 2;
		if (check(mid) != 1){
			l = mid;
		}else{
			r = mid;
		} // end if
	} // end while
	return l;
}


int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	v.clear();
	
	cin >> N >> Q;
	cin >> s;

	rep (i, Q){
		char a, b; cin >> a >> b;
		v.push_back(C(a,b));
	} // end rep
	
	int l = left_border();
	int r = right_border();

	int res = max(0, r - l + 1);
	cout << res << endl;
	
	return 0;
}