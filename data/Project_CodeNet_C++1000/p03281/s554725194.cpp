#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=1;i<=(int)(n);i++)
#define ll long long

int main(){
    int N,count=0;
    cin >> N;
    for(int i=1;i<=N;i+=2){
        int c=0;
        rep(j,i){
            if((i%j)==0)c++;
        }
        if(c==8)count++;
    }
    cout << count << endl;
}