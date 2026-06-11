#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

//#define int long long
//signed main(){
int main() {
//    ios_base::sync_with_stdio(false);
//    cin.tie(NULL);
    int d,tg;
    cin >> d >> tg;
    vector<int> p(d);
    vector<int> c(d);
    for(int i = 0; i < d; i++) {
        cin >> p[i] >> c[i];
    }


    int ans=1e9;
    for(int bit = 0; bit < (1<<d); bit++) {
        int pt=0;
        int cnt=0;
        for(int i = 0; i < d; i++) {
            if(bit & (1<<i)){
                cnt+=p[i];
                pt+=p[i]*(i+1)*100+c[i];
            }
        }

//        cout << bit << " " << bitset<16>(bit) << "\n";

        if(pt<tg){
            int j=d-1;
            while(bit & (1<<j)) j--;
            int add=min(p[j]-1,(tg-pt+((j+1)*100)-1)/((j+1)*100));
            cnt+=add;
            pt+=add*(j+1)*100;
        }

        if(pt>=tg){
            ans=min(ans,cnt);
        }
    }
    cout << ans << "\n";


    return 0;
}