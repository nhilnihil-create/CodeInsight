#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
struct point{int x;int y;};
int i,j,k,count1=0,count2=0;
int digitsum(int n){
    string s=to_string(n);
    int sum=0;
    int d=1;
    for(int e=0;e<s.length();e++){
        sum+=(n/d)%10;
        d*=10;
    }
    return sum;
}

int main(){
    int n,minv,q;
    cin>>n;
    minv=n;
    rep(i,n){
        if(i==0)continue;
        q=n-i;
        minv=min(minv,digitsum(i)+digitsum(q));
    }
    cout<<minv<<endl;
}