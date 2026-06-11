#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n;
ll a[200002];

int main(){
    cin >> n;
    for(ll i=0;i<n;i++) cin >> a[i];
    ll res=0;
    ll right=0;
    ll sum=0;
    for(ll left=0;left<n;left++){
        while(right<n&&(sum^a[right])==(sum+a[right])){
            sum+=a[right];
            right++;
        }
        res+=right-left;
        if(left==right) right++;
        else sum-=a[left];
    }
    cout << res << endl;
}