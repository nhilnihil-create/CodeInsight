
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()


int main(){
    int n, a, b;
    cin >> n >> a >> b;
    int ans=0;
    for(int i=0; i<=n; i++){
        int count=0,temp=i;
        while(temp != 0){
            count += temp % 10;
            temp /= 10;
        }
        if(a <= count && count <= b){
            ans += i;
        }
    }
    cout << ans << endl;

}