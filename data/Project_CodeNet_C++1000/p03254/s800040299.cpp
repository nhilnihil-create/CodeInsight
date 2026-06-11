#include <bits/stdc++.h>
 
using namespace std;
#define repr(i,a,b) for (int i=a; i<b; i++)
#define rep(i,n) for (int i=0; i< (int) n; i++)
#define PI  3.14159265358979323846264338327950
 
 
int main () {
    int N, x;
    cin >> N >> x;

    vector<int>a(N);
    rep(i,N)cin >> a[i];

    sort(a.begin(),a.end());

    int ans=0;
    int i =0;
    for(int i =0;  i <a.size() ; i++){
        if(i == a.size()-1){
            if(x == a[i]){
                ans +=1;
                break;
            }else break;
        }
        
        if(x >= a[i]){
            ans += 1;
            x -= a[i];
        }
    }


    cout << ans << endl;

}
