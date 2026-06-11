#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int ar[501][3];
int main() {
    int n;cin>>n;
    for(int i=0;i<n-1;i++) {
        for(int j=0;j<3;j++) cin>>ar[i][j];
    }
    for(int i=0;i<n-1;i++) {
        ll sum = ar[i][1];
        for(int j=i;j<n-1;j++) {
            sum = ((sum-1) / ar[j][2] + 1) * ar[j][2];
            if(sum < ((ar[j][1]-1) / ar[j][2] + 1) * ar[j][2]) 
                sum = ((ar[j][1]-1) / ar[j][2] + 1) * ar[j][2];
            sum += ar[j][0];
        }
        cout<<sum<<"\n";
    }
    cout<<"0\n";
}