#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
    
    if (b==0) {
        return a;
    } else {
    
        int c;
        while (a%b!=0) {
            c=a%b;
            a=b;
            b=c;
        }
        return b;
    }
}


int main(){
    // Your code here!
    int n;
    
    cin >> n;
    
    vector<int> a(n);
    
    for (int i=0; i<n; i++) {
        cin >> a[i];
    }
    
    vector<int> left(n);
    left[0]=0;
    for (int i=1; i<n; i++) {
        int x = max(left[i-1],a[i-1]);
        int y = min(left[i-1],a[i-1]);
        left[i] = gcd(x,y);
    }
    
    
    vector<int> right(n);
    right[n-1]=0;
    for (int i=n-2; i>-1; i--) {
        //cout << i << endl;
        int x = max(right[i+1],a[i+1]);
        int y = min(right[i+1],a[i+1]);
        right[i] = gcd(x,y);
    }
    
    int ans = 0;
    for (int i=0; i<n; i++){
        ans=max(ans,gcd(left[i],right[i]));
    }
    
    cout << ans << endl;
    return 0;
}
