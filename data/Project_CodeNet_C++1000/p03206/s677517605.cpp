#define _USE_MATH_DEFINES
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,n)         for(int i=0; i<(n); i++)
#define P pair<int, int>
#define prtd(n, var)     cout << fixed << setprecision(n) << var << "\n"

//----------------------------------------------------

int main(){
    int d; cin >> d;
    string s = "Christmas";
    int tmp = 25 - d;
    for(int i = 0; i < tmp; i++){
        s += " Eve";
    }
    cout << s << endl;
}