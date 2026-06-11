#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);++i)
#define FOR(i,n,j) for(int i=(j);i<(n);++i)
#define rrep(i,n) for(int i=(n);i>=0;--i)
#define ssort(n) sort((n).begin(),(n).end())
#define rsort(n) sort((n).begin(),(n).end(),greater<ll>())
using ll=long long;
using ld=long double;
typedef pair<int,int> P;
#define Yes cout << "Yes" << endl
#define No cout << "No" << endl
#define YES cout << "YES" << endl
#define NO cout << "NO" << endl
#define INF 117117117

int main()
{
    int N;
    cin >> N;
    vector<ll> a(N);
    rep(i,N){
        cin >> a[i];
	}
    int size=N;
    int size_minus;
    rsort(a);
    while(size>1){
        size_minus=0;
        rep(i,size-1){
            a[i]=a[i]%a[size-1];
            if(a[i]==0){
                size_minus++;
			}
		}
        rsort(a);
        size-=size_minus;
	}
    cout << a[0] << endl;

}