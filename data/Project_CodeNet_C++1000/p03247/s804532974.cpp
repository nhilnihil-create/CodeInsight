#include<bits/stdc++.h>
using namespace std;

#define int long long

#define pb push_back
#define mp make_pair
#define st first
#define nd second
typedef pair < int , int > pp;
const int N = 1e3 + 3;

int X[N], Y[N];

signed main(){
    int n;
    cin >> n;
    int h = -1;
	for(int i=1; i<=n; i++){
        cin >> X[i] >> Y[i];
        int t = ((X[i] + Y[i]) % 2 + 2) % 2;
        if(h != -1 && t != h){
            cout << -1;
            return 0;
        }
        h = (t+2) % 2;
    }
if(h == 1){
    cout << "31\n";
    for(int i=30; i>=0; i--)
        cout << (1LL << i) << " ";
    cout << "\n";
    for(int i=1; i<=n; i++){
        int x = X[i];
        int y = Y[i];
        string ans = "";
        for(int j=30; j>=0; j--){
            int t = 1LL << j;
    	    int temp = x;
            x += x < 0 ? t : -t;
        	if(llabs(x) + llabs(y) < t){
                ans += temp < 0 ? 'L' : 'R';
                continue;
            }
            
			x = temp;
            ans += y < 0 ? 'D' : 'U';
            y += y < 0 ? t : -t;
        }
        
        cout << ans << endl;
    }
return 0;
}
		cout << "32\n";
    cout << 1 << " ";
    for(int i=30; i>=0; i--)
        cout << (1LL << i) << " ";
    cout << "\n";
    for(int i=1; i<=n; i++){
        int x = X[i];
        int y = Y[i];
        string ans = "L";
        x++;
        for(int j=30; j>=0; j--){
            int t = 1LL << j;
    	    int temp = x;
            x += x < 0 ? t : -t;
        	if(llabs(x) + llabs(y) < t){
                ans += temp < 0 ? 'L' : 'R';
                continue;
            }
            
			x = temp;
            ans += y < 0 ? 'D' : 'U';
            y += y < 0 ? t : -t;
        }
        
        cout << ans << endl;
    }
    
    return 0;
}