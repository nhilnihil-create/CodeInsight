#include <bits/stdc++.h>
using namespace std;
double dp[301][301][301];
int n;

double solve(int a, int b, int c) {
    //cout<<a<<" "<<b<<" "<<c<<endl;
    
    if(a<0 || b<0 || c<0) return 0;
    
    if(a==0 && b==0 && c==0) return 0;
    
    if(dp[a][b][c]>0) return dp[a][b][c];
    
    double F = n + a*solve(a-1,b,c) + b*solve(a+1,b-1,c) + c*solve(a,b+1,c-1);
    
    F = F/(a+b+c);
    
    return dp[a][b][c] = F;
}

int main() 
{
    int x, a = 0, b = 0, c = 0;
    cin >> n;
    
    for(int i=0;i<n;i++){
        cin >> x;
        if(x==1) a++;
        else if(x==2) b++;
        else if(x==3) c++;
    }
    
    double ans = solve(a,b,c);
    
    cout<<fixed<<setprecision(10)<<ans<<endl;
	return 0;
}