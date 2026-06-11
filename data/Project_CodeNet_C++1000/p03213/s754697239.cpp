#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

//#define int long long
//signed main(){
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;

    map<int,int> ap;
    for(int m = 2; m <= n; m++) {
        int div=2;
        int tm=m;
        while(div*div<=tm) {
            if(tm%div==0){
                ap[div]++;
                tm/=div;
            }
            else div++;
        }
        ap[tm]++;
    }
    ap[1]=1;

    int sf=0;
    int tf=0;
    int ft=0;
    int fv=0;
    int tr=0;

    for(auto itr = ap.begin(); itr != ap.end(); itr++) {
        int tmp=itr->second;
        if(tmp>=74) sf++;
        else if(tmp>=24) tf++;
        else if(tmp>=14) ft++;
        else if(tmp>=4) fv++;
        else if(tmp>=2) tr++;
        else continue;
    }

    tf+=sf;
    ft+=tf;
    fv+=ft;
    tr+=fv;

//    cout << "75 " << sf << "\n";
//    cout << "25 " << tf << "\n";
//    cout << "15 " << ft << "\n";
//    cout << "05 " << fv << "\n";
//    cout << "03 " << tr << "\n";

    int ans=0;
    ans+=sf;
    ans+=tf*(tr-1);
    ans+=ft*(fv-1);
    ans+=fv*(fv-1)*(tr-2)/2;

    cout << ans << "\n";
    return 0;
}