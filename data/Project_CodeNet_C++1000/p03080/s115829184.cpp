#include<bits/stdc++.h>
typedef long long ll;
#define INF 100000000
#define MOD 100000007
int dx[4]={1,0,-1,0},dy[4]={0,-1,0,1};
using namespace std;
int main(void){
    int n;
    cin>>n;
    string s;
    cin>>s;
    int r=0,b=0;
    for(int i=0;i<n;i++){
        if(s[i]=='R')r++;
        else b++;
    }
    if(r>b){
        cout<<"Yes"<<endl;
    }else{
        cout<<"No"<<endl;
    }
    return 0;
}