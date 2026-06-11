#include<bits/stdc++.h> 
//#define <- プログラムの文字列を置換する
//typedef <- 新しい型に名前を付けるためのキーワード

using namespace std;

#define MAX_N 1

typedef long long ll;

const double PI = 3.141592653589793;
const long long MOD = 1e9 + 7;
const long long INF = 1e15;


int main(){
    int N;
    cin >> N;
    int a[N];
    int maxi = 0;
    int sum = 0;
    for(int i = 0; i < N; i++){
        cin >> a[i];
        sum += a[i];
        maxi = max(maxi,a[i]);
    }
    if(sum - maxi > maxi) cout <<"Yes" << endl;
    else cout << "No" << endl;
    return 0;
}