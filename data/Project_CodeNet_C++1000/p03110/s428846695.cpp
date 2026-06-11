 #include <bits/stdc++.h>
#include <numeric>
using namespace std;
#define ll long long

int main(){
//A 13:25 13:37
//B 13:37
    int N;
    cin >> N;
    vector<double> X(N);
    vector<string> U(N);
    long double ans = 0;
    int multi = 0;
    /////////////////////
    for (int i = 0; i < N;i++)
    {
        cin >> X[i] >> U[i];
        if(U[i] == "JPY"){
            ans += X[i];
        }
        else{

            ans += X[i] * 380000;
        }
    }
    cout << ans << endl;
}