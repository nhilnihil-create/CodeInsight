#include <bits/stdc++.h>
#define N int(2e5+5)
#define mod 1000000007
using namespace std;
typedef long long ll;
ll ans;

int main(){
    int n, k;
    cin >> n >> k;
    int arr[n];
    for(int i=0; i<n; i++) cin >> arr[i];
    n--;
    if(n%(k-1)) cout << n/(k-1)+1;
    else cout << n/(k-1);
    return 0;
}
