#include <bits/stdc++.h>
#define ALL(A) (A).begin(),(A).end()
#define ll long long
#define rep(i,n) for(int i=0;i<(n);i++)

const ll mod = 1e9+7;
const ll INF = -1*((1LL<<63)+1);
const int inf = -1*((1<<31)+1);

using namespace std;
int cnt[6];
int main(void){
	cin.tie(0);
	ios::sync_with_stdio(false);
	int N = 3;

    rep(i,N){
        int a,b;
        cin >> a >> b;
        cnt[a]++;
        cnt[b]++;
    }
    rep(i,5){
        if(cnt[i]>2){
            cout << "NO" << endl;
            return 0;
        }
    }
    cout  << "YES" << endl;
}