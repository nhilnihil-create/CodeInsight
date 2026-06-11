#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
struct point{int x;int y;};
int i,j,k,count1=0,count2=0;

int main(){
    int n,h,w;
    cin>>n>>h>>w;
    if(n<h||n<w)cout<<0<<endl;
    else{
        cout<<(n-h+1)*(n-w+1)<<endl;
    }
}