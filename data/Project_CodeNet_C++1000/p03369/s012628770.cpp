#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;

int main(){
    string S;
    cin >> S;
    int price = 700;
    if(S[0] == 'o'){price += 100;}
    if(S[1] == 'o'){price += 100;}
    if(S[2] == 'o'){price += 100;}
    cout << price << endl;
}