#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    int sum=0;
    for(int i=0;i<n;i++){
        cin >> a[i];
        sum+=a[i];
    }
    double ave=(double)sum/n;
    int ans=-1;
    int m=-1;
    for(int i=0;i<n;i++){
        if(abs(m-ave)>abs(a[i]-ave)){
            m=a[i];
            ans=i;
        }
    }
    cout << ans << endl;
}