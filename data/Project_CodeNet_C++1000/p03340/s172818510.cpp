#include <bits/stdc++.h>
#define div1 1000000007
const long long INF = 1LL << 60;
using namespace std;
typedef long long ll;
typedef long double ld;
// a>b -> a==b;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
// a<b -> a==b;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

int main(void)
{
    ll N, i, left, right=0, sum=0, ans=0;

    cin >> N;

    vector<ll> A(N);

    for(i=0; i<N; i++){
        cin >> A[i];
    }

    left = 0;

    for(left=0; left<N; left++){
        while(right<N && (sum ^ A[right]) ==(sum + A[right])){
            sum += A[right];
            right++;
        }

        ans += (right-left);

        if(right==left) right++;
        else sum -= A[left];
    }

    cout << ans << endl;

    return 0;
}