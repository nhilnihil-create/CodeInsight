#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using ull = long long unsigned;
using P = pair<int,int>;
const int INF=1001001;
const int NMAX=8;

//head

struct pcake{

	ll a;
	ll b;
	ll c;
	pcake(ll a1,ll b1,ll c1){
		a=a1;b=b1;c=c1;
	}

	bool operator<(const pcake& other) const {
		return a < other.a;
	}
};

int main()
{
	int x,y,z,k;
	cin>>x>>y>>z>>k;
	vector<ll> A(x);
	vector<ll>B(y);
	vector<ll> C(z);
	rep(i,x)cin>>A[i];
	rep(i,y)cin>>B[i];
	rep(i,z)cin>>C[i];
	sort(A.begin(),A.end());
	sort(B.begin(),B.end());
	sort(C.begin(),C.end());


	ll now=A[x-1]+B[y-1]+C[z-1];

	priority_queue <pair<ll,pcake>> q;
	pcake p1(x-1,y-1,z-1);
	q.push(make_pair(now,pcake(x-1,y-1,z-1)));
	set<ll>s;

	rep(i,k){
		auto qnow=q.top();
		q.pop();
		cout<<qnow.first<<endl;



	 ll a1=qnow.second.a;
	 ll b1=qnow.second.b;
	 ll c1=qnow.second.c;

	 ll hash=a1*100000000+b1*10000+c1;
	 s.insert(hash);

		if (a1>0){

			//cout<<p.a<<endl;

			ll s1=A[a1-1]+B[b1]+C[c1];
		//	cout<<s1<<endl;
			pcake pnow1(a1-1,b1,c1);
			if (s.find((a1-1)*100000000+b1*10000+c1)==s.end())
			//cout<<pnow1.a<<endl;
			q.push(make_pair(s1,pnow1));
			s.insert((a1-1)*100000000+b1*10000+c1);
		}


		if (b1>0){
			ll s2=A[a1]+B[b1-1]+C[c1];
			pcake pnow2(a1,b1-1,c1);
					if (s.find(a1*100000000+(b1-1)*10000+c1)==s.end())
				q.push(make_pair(s2,pnow2));
					s.insert(a1*100000000+(b1-1)*10000+c1);
			}


		if (c1>0){
			ll s3=A[a1]+B[b1]+C[c1-1];
		//	cout<<s3<<'s'<<endl;
			pcake pnow3={a1,b1,c1-1};
				if (s.find(a1*100000000+b1*10000+c1-1)==s.end())
				q.push(make_pair(s3,pnow3));}
					s.insert(a1*100000000+b1*10000+c1-1);

	}



}
