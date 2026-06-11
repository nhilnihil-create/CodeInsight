#include<bits/stdc++.h>
using namespace std;
#define INFTY 1<<20
#define rep(i,n) for (ll i = 0; i < (n); ++i)
typedef long long int ll;
using ipair = pair<int,int>;
bool operator< (const ipair a, const ipair b){return a.first < b.first;};
const int MOD=1000000007;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

int main(){ 
    int n;cin>>n;
    string s="";
    if(n==0)s = s + to_string(0);
    else{
    while(abs(n)>=1){
        if(n%(-2)!=0){
            s =  to_string(abs(n%(-2)))+s;
            n=(n-1)/(-2);
            //printf("n:%d s:%s\n",n,s.c_str());
        }
        else{
            s =  to_string(n%(-2))+s;
            n=n/(-2);
            //printf("n:%d s:%s\n",n,s.c_str());
        }
        
        
        
    }}
   //if(n==1)s = s + to_string(1);
    
    cout<<s<<endl;
    return 0;
}