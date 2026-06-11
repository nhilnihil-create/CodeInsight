#include <bits/stdc++.h>
#define float long double
#define foi(i,n) for(int i = 0 ;i < n ; i++)
using namespace std;
float dp[301][301][301];



// dp[i][j][k] = we remove the Ith index ka element and graph has j non zero components currently having k elements

float solve(int i,int j,int k,float n){
    if(i == 0 && j == 0 && k == 0) return 0;
    if(i<0 || j <0 || k <0) return 0;
    if(dp[i][j][k]!=-1) return dp[i][j][k];
    int zero = n - i - j - k ;
    float p0 = zero/n;
    float p1 = i/n; // one
    float p2 = j/n; // two
    float p3 = k/n; // three

    float a,b,c;
    a = p1*solve(i-1,j,k,n);
    b = p2*solve(i+1,j-1,k,n);
    c = p3*solve(i,j+1,k-1,n);

    return dp[i][j][k] = (1+a+b+c)/(1-p0);

}


int32_t  main(){
    int n;
    cin >> n;
    foi(i,301){
        foi(j,301){
            foi(k,301) dp[i][j][k] = -1;
        }
    }
    int one,two,three;
    one =two = three = 0;
    foi(i,n){
        int x;
        cin >> x;
        if(x == 1) one++;
        else if(x == 2) two++;
        else if(x == 3) three++;
    }
    cout << fixed << setprecision(10);
    cout << solve(one,two,three,n);
}
