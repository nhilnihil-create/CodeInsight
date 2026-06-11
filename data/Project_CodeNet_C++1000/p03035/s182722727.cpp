#include<bits/stdc++.h>
//#include<atcoder/all>

using namespace std;
//using namespace atcoder;

int main(){
    int a,b;
    cin>>a>>b;
    if(a>=13) b=b;
    else if(a>=6) b/=2;
    else b=0;
    cout<<b<<endl;
}
