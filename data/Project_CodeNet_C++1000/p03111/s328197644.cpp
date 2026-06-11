#include <bits/stdc++.h>
using namespace std;
int l[9];
int n,a,b,c;
int ans;
int dfs(int number,int A,int B,int C){
    if(number==n){
        if(A>0 && B>0 && C>0)ans=abs(A-a)+abs(B-b)+abs(C-c)-30;
        else ans=1e9;
        return ans;
    }
    else{
        if(number==0)ans=1e9;
        int ans1=dfs(number+1,A+l[number],B,C)+10;
        int ans2=dfs(number+1,A,B+l[number],C)+10;
        int ans3=dfs(number+1,A,B,C+l[number])+10;
        int ans4=dfs(number+1,A,B,C);
        return min(min(min(ans1,ans2),ans3),ans4);
    }
}

int main(){
    cin >> n >> a >> b >> c;
    for(int i=0;i<n;i++)cin >> l[i];
    cout << dfs(0,0,0,0) << endl;
}