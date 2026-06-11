#include <bits/stdc++.h> 
#include <vector>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define size_of_array(array) (sizeof(array)/sizeof(array[0]))
using ll =long long;
using namespace std;
using Graph=vector<vector<int>>;
using Field=vector<vector<int>>;

template<class T> inline bool chmin(T& a,T b){if(a>b){a=b;return 1;}return 0;}
template<class T> inline bool chmax(T& a,T b){if(a<b){a=b;return 1;}return 0;}

int main(){
    int a[5]={};
    rep(i,5)cin>>a[i];
    int sum=0;
    int b=10;
    rep(i,5){
        int s=a[i]%10;
        int t=a[i]/10;
        if(s!=0){
            a[i]=(t+1)*10;
            b=min(b,s);
        }
        sum+=a[i];
    }
    cout<<sum-10+b<<endl;
}



