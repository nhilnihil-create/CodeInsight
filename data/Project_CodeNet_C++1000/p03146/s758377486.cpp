#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
#define prtd(var, i) cout << fixed << setprecision(i) << var << endl;
#define ll long long
using namespace std;

int main(){
    int s; cin >> s;
    int cnt = 0;
    vector<int> a;
    a.push_back(s);
    while(true){
        cnt++;
        if(s % 2 == 0){
            s /= 2;
        }else{
            s = 3*s + 1;
        }
        rep(i, a.size()){
            if(a[i] == s) {
                cout << cnt+1 << endl;
                return 0;
            }
        }
        a.push_back(s);
    }


}
