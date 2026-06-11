#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
#define pb push_back





int main(){
    int n;
    cin >> n;
    int a[n];
    int ans=pow(3,n);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }

    int kisuu_count=1;

    for(int i=0;i<n;i++){
        int kisuu=0;
        if(a[i]%2==0){
            kisuu=2;
        }else{
            kisuu=1;
        }
        kisuu_count=kisuu_count*kisuu;
    }
    cout << ans-kisuu_count << endl;
    return 0;
}