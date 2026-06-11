#include <bits/stdc++.h>
using namespace std;
#define N 3050
int memo[N][N];
string a,b;

int dp(int curr1 , int curr2) {
    if (curr1 >= a.length() || curr2 >= b.length()) return 0;
    int &sol = memo[curr1][curr2];
    if (sol != -1) return sol;
    sol = max(dp(curr1 + 1 , curr2) , dp(curr1 , curr2 + 1));
    if (a[curr1] == b[curr2]) {
        sol = max(
            dp(curr1 + 1 , curr2 + 1) + 1 ,
            sol
        );
    }
    return sol;
}

void dp2(int curr1 , int curr2) {
    if (curr1 >= a.length() || curr2 >= b.length()) return;
    int inc1 = dp(curr1 + 1 , curr2), inc2 = dp(curr1 , curr2 + 1),take;
    if (a[curr1] == b[curr2]) take = dp(curr1 + 1 , curr2 + 1) + 1;
    else take = INT_MIN;
    if (inc1 >= take && inc1 >= inc2) {
        dp2(curr1 + 1 , curr2);
    } else if (inc2 >= take && inc2 >= inc1) {
        dp2(curr1 , curr2 + 1);
    } else if (take >= inc1 && take >= inc2) {
        printf("%c" , a[curr1]);
        dp2(curr1 + 1 , curr2 + 1);
    }
}

int main() {
    char x[N],y[N]; scanf("%s %s" , x , y);
    a = x, b = y;
    memset (memo , -1 , sizeof memo);
    dp(0 , 0);
    dp2(0 , 0);
    printf("\n");
}
