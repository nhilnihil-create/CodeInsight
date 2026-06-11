#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

#define rep(i, n) for(int i = 0; i < n; i++)
#define repn(i, n) for(int i = 1; i <= n; i++)
#define repr(i, n) for(int i = n-1; i >= 0; i--)
#define all(x) (x).begin(), (x).end()
#define lint long long


int main(){
    int a, b; cin >> a >> b; a--; b--;
    cout << 100 << " " << 100 << endl;
    rep(i, 100){
        string res = "";
        rep(j, 100){
            if(i < 50){
                if(i % 2 == 1 || j % 2 == 1) res += "#";
                else{
                    if(a == 0) res += "#";
                    else{
                        res += ".";
                        a--;
                    }
                }
            }
            else{
                if(i % 2 == 0 || j % 2 == 1) res += ".";
                else{
                    if(b == 0) res += ".";
                    else{
                        res += "#";
                        b--;
                    }
                }
            }
        }
        cout << res << endl;
    }
}