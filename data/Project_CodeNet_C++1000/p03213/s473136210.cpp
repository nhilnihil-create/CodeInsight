#include<bits/stdc++.h>
#define M 1000000007
#define pi ld(acos(-1.0))
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define Rep(i,n) for(int i=1;i<(int)(n);i++)
#define repp(i,a,b)  for(ll i=a;i<=(ll)(b);i++)
#define Repp(i,a,b)  for(int i=a;i>=(int)(b);i--)
#define cs ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define fi first
#define se second
#define ii pair<int,int>
#define bye(x) {cout<<x;return 0;}
typedef long long ll;
typedef long double ld;
using namespace std;
vector<int> v(101);int n;
void pre() {
    repp(i,1,n) {
        int q=sqrt(i),k=i;
        repp(j,2,q) {
            if(k%j==0) {
                while(k%j==0) {k/=j;v[j]++;}
            }
        }
        if(k>1) v[k]++;
    }
}
int cal(int x) {
    int t=0;
    repp(i,2,n) {
        if(v[i]>=x-1) t++;
    }
    return t;
}
int main() {
    cs
    cin>>n;
    pre();
    cout<<cal(75)+cal(25)*(cal(3)-1)+cal(15)*(cal(5)-1)+(cal(5)*(cal(5)-1)*(cal(3)-2))/2;
}