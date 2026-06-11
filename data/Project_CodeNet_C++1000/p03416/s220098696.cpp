#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long 
#define endl '\n'
#define pii pair<int, int>

int main(){
    int a, b;
    cin >> a >> b;

    int ans=0;
    for(int i=a; i<=b; ++i){
        int k = i%10; 
        int l = i/10%10; 
        int m = i/1000%10; 
        int n = i/10000%10; 

        if(k==n && l==m)
            ans++;
    }
    cout << ans;
}
