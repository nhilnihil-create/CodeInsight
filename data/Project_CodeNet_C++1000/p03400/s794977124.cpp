#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;
#define ll long long
const int inf = 1000000000;

int main(){
    int n,d,x;
    cin >> n >> d >> x;

    vector<int> a(n);

    rep(i,n){
    cin >> a[i];        
    }

    int ans =0;


    
    rep(i,n){
    int date=1;
    int j=1;
    while(date<=d){
        
        date=a[i]*j+1;
       // cout << date << endl;
        j++;
        ans++;

      }   
    }

    cout << ans+x << endl;
    return 0;

}