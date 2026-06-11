#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> P;
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
#define _GLIBCXX_DEBUG 

int main(){
    string S;
    cin>>S;
    int number[4];
    rep(i,4){
        number[i]=S[i]-'0';
    }
    char puramai[3];

    for(int bit=0; bit<(1<<3);bit++){
        int sum=number[0];
        rep(i,3){
            if(bit&(1<<i)){
                sum+=number[i+1];
            }
            else sum-=number[i+1];
        }
        if(sum==7){
            rep(i,3){
                if(bit&(1<<i)) puramai[i]='+';
                else puramai[i]='-';
            }
        }
    }

    cout<<number[0]<<puramai[0]<<number[1]<<puramai[1]<<number[2]<<puramai[2]<<number[3]<<"=7"<<endl;
}