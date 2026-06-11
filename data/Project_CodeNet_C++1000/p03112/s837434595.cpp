#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for (int i = 0; i < (n); ++i)
typedef long long ll;
const ll INF = 1e18;

int main() {
	ll A,B,Q,x;
	cin >> A >> B >> Q;
	vector<ll> s(A+2),t(B+2);

	s.at(0)=-INF, s.at(A+1)=INF;
	rep(i,A)
		cin >> s.at(i+1);
	sort(s.begin(), s.end());

	t.at(0)=-INF, t.at(B+1)=INF;
	rep(i,B)
		cin >> t.at(i+1);
	sort(t.begin(), t.end());

	rep(i,Q) {
		ll ws,es,wt,et,l,r,m,d=INF;
		cin >> x;

		l=0,r=A;
		while(l <= r) {
			m = (l+r)/2;
			if(x > s.at(m))
				l = m+1;
			else if(x < s.at(m))
				r = m-1;
			else {
				l=m,r=m;
				break;
			}
		}
		r = max(min(A+1,r), 0ll);
		l = max(min(A+1,l), 0ll);
		ws=s.at(r), es=s.at(l);

		l=0,r=B;
		while(l <= r) {
			m = (l+r)/2;
			if(x > t.at(m))
				l = m+1;
			else if(x < t.at(m))
				r = m-1;
			else {
				l=m,r=m;
				break;
			}
		}
		r = max(min(B+1,r), 0ll);
		l = max(min(B+1,l), 0ll);
		wt=t.at(r), et=t.at(l);

		if(ws < wt)
			d = min(d,x-ws);
		else
			d = min(d,x-wt);
		if(es < et)
			d = min(d,et-x);
		else
			d = min(d,es-x);
		d = min(d,(x-ws)*2+et-x);
		d = min(d,(x-wt)*2+es-x);
		d = min(d,(es-x)*2+x-wt);
		d = min(d,(et-x)*2+x-ws);

		cout << d << endl;
	}
}