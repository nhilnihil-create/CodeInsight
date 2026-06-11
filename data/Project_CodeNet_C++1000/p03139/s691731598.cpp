#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
struct point{int x;int y;};
int i,j,k,count1=0,count2=0;

int main(){
    int n,a,b;
    cin>>n>>a>>b;
    cout<<min(a,b)<<" "<<(a+b<=n?0:a+b-n)<<endl;
}