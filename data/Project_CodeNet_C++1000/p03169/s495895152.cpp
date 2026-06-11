#include <bits/stdc++.h>
#define ll long long int
#define ld long double
#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define mp make_pair
#define pb push_back
#define vll vector<ll>
#define mod(n) (n) % 1000000007
#define sp << " "
#define precision(n) cout << fixed << setprecision(n);
#define startTime time_t start, end;time(&start);
#define endTime time(&end);double tt = double(end-start);cout<<"Time taken : "<<fixed<<tt<<setprecision(5);cout <<" sec"<< endl;
 
using namespace std;
 
int main() { 
    IOS;
    precision(10);
    ll n;
    cin >> n;
    vector<double> p(n, 0);
    int cnt1 = 0, cnt2 = 0, cnt3 = 0;
    for (int i = 0; i < n; i++) {
    	cin >> p[i];
    	if (p[i] == 1) cnt1++;
    	else if (p[i] == 2) cnt2++;
    	else cnt3++;
    }
    vector<vector<vector<double>>> dp(cnt3 + 1, vector<vector<double>>(cnt3 + cnt2 + 1, vector<double>(cnt3 + cnt2 + cnt1 + 1, 0.0)));

    for (int i = 0; i < cnt3 + 1; i++) {
    	for (int j = 0; i + j < cnt3 + cnt2 + 1; j++) {
    		for (int k = 0; i + j + k < cnt3 + cnt2 + cnt1 + 1; k++) {
    			if (i + j + k > cnt3 + cnt2 + cnt1 || i + j + k == 0) continue;
    			double a = 0.0, b = 0.0, c = 0.0, d = 0.0;
    			if (k) a = dp[i][j][k - 1] * (double)(k) / (i + j + k);
    			if (j) b = dp[i][j - 1][k + 1] * (double)(j) / (i + j + k);
    			if (i) c = dp[i - 1][j + 1][k] * (double)(i) / (i + j + k);
    			d = (double)(n) / (i + j + k);
    			dp[i][j][k] = a + b + c + d;
    		}
    	}
    }
    cout << dp[cnt3][cnt2][cnt1] << endl;    
}