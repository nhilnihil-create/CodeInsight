#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;
typedef vector<int> vi;

#define FOR(i,a,b) for (int i=a;i<b;i++)
#define fi first
#define se second
#define pb push_back

int n;
pii points[1005];
int arr[1005];

vector<LL> powers;
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    FOR(i,1,n+1) cin >> points[i].fi >> points[i].se;
    FOR(i,1,n+1){
        arr[i] = ((((points[i].fi + points[i].se)%2)+4)%2);
    }
    FOR(i,2,n+1){
//cout << arr[i] << ":";
        if (arr[i] != arr[i-1]){
            puts("-1");
            return 0;
        }
    }
    if (arr[1] == 0) powers.pb(1);
    for (LL k = 1; k <= 2e9; k<<=1) powers.pb(k);
    reverse(powers.begin(), powers.end());

    cout << powers.size() << '\n';
    for (int i = 0; i < powers.size(); i++){
	cout << powers[i] << (i == powers.size() - 1 ? '\n' : ' ');
    }
    for (int i = 1; i <= n; i++){
	for (int j = 0; j < powers.size(); j++){
	    if (abs(points[i].fi) >= abs(points[i].se)){
		if (points[i].fi < 0){
		    cout << 'L';
		    points[i].fi += powers[j];
		} else {
		    cout << 'R';
		    points[i].fi -= powers[j];
		}
	    } else {
		if (points[i].se < 0){
		    cout << 'D';
		    points[i].se += powers[j];
		} else {
		    cout << 'U';
		    points[i].se -= powers[j];
		}
	    }
	}
	cout << '\n';
    }
    return 0;
}
