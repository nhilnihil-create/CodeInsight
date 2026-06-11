#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
#define FAST ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define ll long long
#define mm(arr) memset(arr, 0, sizeof(arr))
#define scanArray(a,n) for(int i = 0; i < n; i++){cin >> a[i];}
#define pb push_back
#define PI 3.141592653589793
#define MOD 1000000007

using namespace std;
int main(){
    FAST
    ll n,x; cin >> n >> x;
    ll m[n];
    ll cnt=0,sum=0;
    for(int i=0;i<n;i++){
        cin >> m[i];
        sum+=m[i];
    }
    sort(m,m+n);
    ll i=0;
    if(sum>x){
        while(sum>0){
            sum-=m[i];
            cnt++;
            i++;
        }
    }
    else{
        cnt=n;
        x-=sum;
        while(x>0){
            if(x-m[0]<0){
                break;
            }
            x-=m[0];
            cnt++;
        }
    }
    cout << cnt << endl;

    return 0;
}
