#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;
#define ll long long
const int inf = 1000000000;

    int main (){
        string s;
        cin >> s;

        vector<int> a(s.size());
        rep(i,s.size()){
            a[i]=0;
        }

        int ans = 0;

        rep(i,s.size()){
            if(s[i]=='A' || s[i]=='C' || s[i]=='G' || s[i]=='T'){
                if(a[i-1]>0 && i>0){
                    a[i]=a[i-1]+1;
                }
                else{
                    a[i]++;
                }

            }
            ans = max(ans,a[i]);
        }
        cout << ans << endl;
        return 0;
    }