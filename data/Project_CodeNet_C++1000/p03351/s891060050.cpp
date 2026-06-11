#define _LIBCPP_DEBUG 0
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll MOD = 1e9 + 7;

int H,W;
char S[22][22];

int DFS(int x, int y, int max){

    return 0;
}


int main(void) {

    int a,b,c,d; cin>>a>>b>>c>>d;

    if(abs(a-c)<=d){
        cout<<"Yes"<<endl;
    }else if(abs(a-b)<=d && abs(b-c)<=d){
        cout<<"Yes"<<endl;
    }else cout<<"No"<<endl;

    return 0;
}