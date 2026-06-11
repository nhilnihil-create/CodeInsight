#include<bits/stdc++.h>
#define ford(i,a,b) for(int i=(a);i>=b;i--)
#define rep1(i,a,b) for(int i=(a);(i)<=(b);(i)++)
#define rep(i,a,b) for(int i=(a);(i)<(b);(i)++)
#define ll long long
#define N 105
#define pql priority_queue<ll>
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
#define rev(a,n) reverse(a,a+n)
using namespace std;
int n,h[N],ans; 
int main() {
	cin>>n;
	rep(i,0,n) cin>>h[i];
	rep(i,0,n) {
		while(h[i]>0) {
        	rep(j,i,n) {
                if(h[j]>0) h[j]--;
                else break;
            }
            ans++;
        }
	}
	cout<<ans;
	return 0;
}