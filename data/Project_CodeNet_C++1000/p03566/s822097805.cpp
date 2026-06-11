#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int n, t[100], s = 0;
    double v[100], w[50000], ans = 0;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> t[i];
    }
    for(int i=0;i<n;i++){
        cin >> v[i];
    }
    w[0] = 0;
    for(int i=0;i<n;i++){
        w[s] = min(w[s], v[i]);
        for(int j=0;j<t[i]*2;j++){
            w[++s] = v[i];
        }
    }
    for(int i=1;i<s;i++){
        w[i] = min(w[i], w[i-1]+0.50);
    }
    w[s] = 0;
    for(int i=s-1;i>0;i--){
        w[i] = min(w[i], w[i+1]+0.50);
    }
    for(int i=0;i<s;i++){
        ans += (w[i] + w[i+1]) / 4.00;
    }
    cout << fixed << setprecision(16) << ans << endl;
	return 0;
}