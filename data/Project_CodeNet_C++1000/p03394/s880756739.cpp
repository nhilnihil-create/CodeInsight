#include<bits/stdc++.h>
using namespace std;
 
#define pb push_back
#define ll long long
#define maxn 100005
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define ms(i) memset(i,0,sizeof(i));
#define ms1(i) memset(i,-1,sizeof(i));
#define F first
#define S second
#define all(x) x.begin(), x.end()
const int mod = 1e9+7;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    if (n == 3) {
        cout << "2 5 63\n";
    }
    else if (n == 4) {
        cout << "2 5 20 63\n";
    }
    else {
            cout << "2 3 4 9 ";
            n -= 4;
        int v[30002] = {};
        v[2] = v[3] = v[4] = v[9] = 1;
        if (n >= 2) {
            v[8] = v[10] = 1;
            n -= 2;
            cout << "8 10 ";
        }
        for (int i = 6 ;i + 3 <= 30000 ; i+= 6) {
            if (n >= 2) {
                if (!v[i-2] && !v[i+2]) {
                    cout << i - 2 <<' '<<i + 2<<' ';
                    n -= 2;
                    v[i-2] = v[i+2] = 1;
                }
            }
            if (n >= 2) {
                if (!v[i-3] && !v[i+3]) {
                    cout << i - 3 <<' '<<i + 3<<' ';
                    n -= 2;
                    v[i-3] = v[i+3] = 1;
                }
            }
            if (n >= 2) {
                if (!v[i-4] && !v[i+4]) {
                    cout << i - 4 <<' '<<i + 4<<' ';
                    n -= 2;
                    v[i-4] = v[i+4] = 1;
                }
            }
        }
        for (int i = 6 ;i <= 30000 ; i+= 6) {
            if (n) {
                if (!v[i]) {
                    cout << i <<' ';
                    n--;
                }
            }
        }
        //cout << n <<"here"<< endl;
        cout << '\n';
    }
}
