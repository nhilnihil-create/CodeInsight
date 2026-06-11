#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef pair<ll, int> li;
typedef pair<int, ll> il;
typedef vector<ii> vii;
typedef vector<il> vil;
typedef vector<li> vli;

#define ff first
#define ss second
//#define pb push_back
#define mp make_pair
#define sz size()
#define all(a)  A.begin(), A.end()
#define mem(a, b)     memset(a, b, sizeof(a))
#define f0(i,b) for(int i=0;i<(b);i++)
#define f1(i,b) for(int i=1;i<=(b);i++)
#define f2(i,a,b) for(int i=(a);i<=(b);i++)
#define fr(i,b,a) for(int i=(b);i>=(a);i--)
#define rep(i,a,b,c) for(int i=(a);i!=(b);i+=(c))


#define forr(i,n) for(i=0; i<n; i++)
#define whilee(i,t) while(i!=t)
#define pb(x) push_back(x);

//sort(A.begin(),A.end());
//binary_search(A.begin(),A.end(),x);
//reverse(A.begin(), A.end());
//cout << *max_element(A.begin(), A.end());
//cout << *min_element(A.begin(), A.end());
//accumulate(A.begin(), A.end(), 0);
//next_permutation(A.begin(), A.end());
//prev_permutation(A.begin(), A.end());


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll i, j, k, a, b, c, l, m, n, p, q, r, s, t, x, y, z, cnt=0, min=INT_MAX;

    cin>>n>>x;
    int A[n];
    forr(i,n)
    {
        cin>>A[i];
    }
    t=abs(x-A[n-1]);
    forr(i,n-1)
    {
       t = __gcd(t,abs(x-A[i]));
    }
     cout<<t<<endl;

    return 0;
}