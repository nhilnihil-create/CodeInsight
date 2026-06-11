#include<bits/stdc++.h>

using namespace std;

const int maxn = 2e5 + 10;
int ar[maxn], ans1[maxn], ans2[maxn], n, x;     

int main(){
    int n;
    cin >> n;
    int ans = n;
    for(int i = 1; i <= n; i++){
        cin >> x;
        ar[x] = i;
    }
    for(int i = n - 1; i >= 1; i--){
        if(ar[i] < ar[i + 1])
             ans1[i] = ans1[i + 1];
        else
            ans1[i] = (n - i);
    }
    for(int i = 2; i <= n; i++){
        if(ar[i] > ar[i - 1])
            ans2[i] = ans2[i - 1];
        else
            ans2[i] = i - 1;
    }
    for(int i = 1; i <= n; i++)
        ans = min(ans, ans2[i] + ans1[i]);

    cout << ans << endl;
}