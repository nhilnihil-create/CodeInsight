#include <bits/stdc++.h>
#define rep(i , n) for(int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
int main (){
    int a;
    cin >> a;
    int L = a / 100;
    int R = a % 100;
    if(1 <= L && L <= 12){
        if(1 <= R && R <= 12){
            cout << "AMBIGUOUS" << endl;
        }
        else{
            cout << "MMYY" << endl;
        }
    }
    else{
        if(1 <= R && R <= 12){
            cout << "YYMM" << endl;
        }
        else{
            cout << "NA" << endl;
        }
    }
}