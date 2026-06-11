#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
#define pb push_back
#define all(v) v.begin(),v.end()
#define fi first
#define se second
#define bigger (char)toupper
#define smaller (char)tolower
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vii;
typedef vector<string> vs;
typedef vector<char> vc;
typedef long long ll;
typedef unsigned long long ull;

int main() {
    int N;
    cin>>N;
    vi A={0};
    rep(i,N) {
        int a;
        cin>>a;
        A.pb(a);
    }
    A.pb(0);
    int sum=0;
    rep(i,N+1) {
        sum+=abs(A[i]-A[i+1]);
    }
    int sum2=sum;
    for(int i=1; i<=N; i++) {
        sum-=abs(A[i]-A[i-1]);
        sum-=abs(A[i+1]-A[i]);
        sum+=abs(A[i+1]-A[i-1]);
        cout<<sum<<endl;
        sum=sum2;
    }
}