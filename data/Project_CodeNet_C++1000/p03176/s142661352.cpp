#include<bits/stdc++.h>
#define ll long long
#define MAX 200005
using namespace std;

int n;
ll dp[MAX*4];
ll height[MAX];
ll beauty[MAX];

void build(int idx, int left, int right) {
    if (left==right) {dp[idx]=beauty[left]; return;}

    int mid=(left+right)/2;
    build(idx*2,left,mid);
    build(idx*2+1,mid+1,right);
    dp[idx]=max(dp[idx*2],dp[idx*2+1]);
}

void update(int idx, int left, int right, int a, ll val) {
    if (left>a || right<a) {return;}
    if (left==right) {dp[idx]=val; return;}

    int mid=(left+right)/2;
    update(idx*2,left,mid,a,val);
    update(idx*2+1,mid+1,right,a,val);
    dp[idx]=max(dp[idx*2],dp[idx*2+1]);
}

ll query(int idx, int left, int right, int a, int b) {
    if (left>=a && right<=b) {return dp[idx];}
    if (left>b || right<a) {return 0;}

    int mid=(left+right)/2;
    return max(query(idx*2,left,mid,a,b),query(idx*2+1,mid+1,right,a,b));
}

int main() {
    cin >> n;
    for (int i=0;i<n;i++) {cin >> height[i];}
    for (int i=0;i<n;i++) {cin >> beauty[i];}

    for (int i=0;i<n;i++) {
        ll mmax=query(1,0,n-1,0,height[i]-1);
        update(1,0,n-1,height[i]-1,mmax+beauty[i]);
    }
    cout << query(1,0,n-1,0,n-1) << endl;
}
