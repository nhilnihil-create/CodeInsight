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
    int n,m;
    cin >> n >> m;
    bool check[m];
    memset(check,false,sizeof check);
    for(int i = 0; i < n ;i++){
        int k;
        cin >> k;
        bool temp[m];
        memset(temp,false,sizeof temp);
        for(int j = 0 ; j < k ; j++){
            int a;
            cin >> a;
            a--;
            temp[a] = true;
        }
        for(int l = 0; l < m ; l++){
            if(i == 0) check[l] = temp[l];
            check[l] = check[l] & temp[l];
        }
    }
    int count = 0;
    for(int i = 0; i < m ;i++){
        if(check[i]){
            count++;
        }
    }
    cout << count << endl;
    return 0;
}