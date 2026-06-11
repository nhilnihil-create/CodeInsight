#include <bits/stdc++.h>
#define mins(x,y) (x=min(x,y))
#define rep(i,n) for(int i=0; i<(n); i++)
using namespace std;
using ll = long long;
using P  = pair<int,int>;
using v  = vector<int>;
using vv = vector<v>;

int main(){
    int n;
    cin >> n;
    
    cout << n*(n-1)/2 -n/2 << endl;
    
    for(int i=1; i<=(n/2)*2; i++){
        for(int j=i+1; j<=(n/2)*2; j++){
            if(i + j == (n/2)*2+1)continue;
            cout << i <<" "<< j << endl;
        }
    }
    
    if(n%2){
        for(int i=1; i<n; i++){
            cout << i <<" "<< n << endl;
        }
    }
    //ぜんぶつなぐと和はn(n+1)/2 - i
    //n=8のばあい
    //1 -> 35 - 8
    //2 -> 34 - 7
    //5 -> 31 - 4
    //8 -> 28 - 1
    
    //n=9のばあい
    //1 -> 44 - 8
    //2 -> 43 - 7
    //5 -> 40 - 4
    //8 -> 37 - 1
    //9 -> 36
    
    return 0;
}