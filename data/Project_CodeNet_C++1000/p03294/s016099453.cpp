#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
struct point{int x;int y;};
int i,j,k,count1=0,count2=0;

int main(){
    int n;
    cin>>n;
    int sum=0,x;
    rep(i,n){
        cin>>x;
        sum+=x-1;
    }
    cout<<sum<<endl;
}