#include <bits/stdc++.h>
#define MAXN 100100
#define pii pair<int, int>
#define pb push_back
typedef long long ll;

using namespace std;

int n;
int a[MAXN];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    cin >> n;
    for(int i = 0; i < n; i++){
    	cin >> a[i];
    }
    sort(a, a + n);
    int g = a[n - 1];
    int best = a[0];
    for(int i = 0; i < n; i++){
    	int d = abs(g - 2 * a[i]);
    	if(d < abs(2 * best - g)){
    		best = a[i];
    	}
    }
    cout << a[n - 1] << " " << best;
}