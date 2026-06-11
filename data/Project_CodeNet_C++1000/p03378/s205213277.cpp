#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;
#define ll long long
const int inf = 1000000000;

    int main (){
     int n,m,x;
     cin >> n >> m >> x;
        
        vector<int> a(m);

        int ansf=0;
        int ansb=0;

        rep(i,m){
            cin >> a[i];
            if(a[i]>x){
                ansb++;
            }
            else{
                ansf++;
            }
        }

        int ans = min(ansf,ansb);

        cout << ans << endl;

        return 0;

    }
