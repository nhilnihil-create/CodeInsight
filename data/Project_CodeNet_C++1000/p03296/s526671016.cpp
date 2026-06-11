#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG //これつけるとA[N]でもいいらしい
//for文のマクロ
 #define rep(i, n) for (int i = 0; i < (int)(n); i++)
 #define big 1000000007
int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    rep(i,n){
        cin >>a[i];
    }
    int count=0;
    int same=1;
    int i=0;
    while(i<n){
        if(a[i]==a[i+1]){
            int j=1;
            while(a[i]==a[i+j]&&i+j<n){
                j++;
            }
            count += j/2;
            i += j;
        }
        else{
            i++;
        }
    }
    cout <<count<<endl;
}