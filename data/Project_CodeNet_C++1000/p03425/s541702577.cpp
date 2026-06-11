#include <bits/stdc++.h>
#define rep(i , n) for(int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
ll m, a, r, c, h;
int main(){
    int n;
    cin >> n;
    rep(i, n){
        string s;
        cin >> s;
        if(s[0]=='M'){
		    m++;
        }
		if(s[0]=='A'){
            a++;
        }
		if(s[0]=='R'){
		    r++;
        }
        if(s[0]=='C'){
		    c++;
        }
		if(s[0]=='H'){
		    h++;
        }
    }
    cout << m * a * h + m * a * c + m * a * r + m * r * c + m * r * h + m * c * h + a * r * c + a * r * h + a * c * h + r * c * h << endl;
}
