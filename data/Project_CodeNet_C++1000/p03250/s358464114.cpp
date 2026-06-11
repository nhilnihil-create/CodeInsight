#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;

const ll LINF = 1e18;
const int INF = 1e9;
const ll MOD = 1000000007;

int main(){

    int a, b, c;
    cin >> a >> b >> c;

    int fi, se, th;
    if(a > b){
        if(b > c){
            fi = a;
            se = b;
            th = c;
        }
        else{
            if(c > a){
                fi = c;
                se = a;
                th = b;
            }
            else{
                fi = a;
                se = c;
                th = b;
            }
        }
    }
    else{
        if(a > c){
            fi = b;
            se = a;
            th = c;
        }
        else{
            if(c > b){
                fi = c;
                se = b;
                th = a;
            }
            else{
                fi = b;
                se = c;
                th = a;
            }
        }
    }

    cout << fi*10 + se + th << endl;
    return 0;
}