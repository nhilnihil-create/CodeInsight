#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<vector<double>>> dp;

double f(int a, int b, int c){
    if(dp[a][b][c] != -1) return dp[a][b][c];

    //cout << a << " " << b << " " << c << endl;
    double ev = 1;
    if(a >= 1) ev += a / (double)n * f(a-1, b,   c  );
    if(b >= 1) ev += b / (double)n * f(a+1, b-1, c  );
    if(c >= 1) ev += c / (double)n * f(a,   b+1, c-1);
    //cout << ev << endl;
    ev /= (a+b+c) / (double)n;//1 - (n-a-b-c) / n;

    dp[a][b][c] = ev;
    return ev;
}

int main(){
    cin >> n;
    dp.assign(n+1, vector<vector<double>>(n+1, vector<double>(n+1, -1)));
    dp[0][0][0] = 0;

    vector<int> sushi(4);
    for(int i=0; i<n; i++){
        int a;
        cin >> a;
        sushi[a] += 1;
    }
    cout << fixed << setprecision(12) << f(sushi[1], sushi[2], sushi[3]) << endl;
    return 0;
}