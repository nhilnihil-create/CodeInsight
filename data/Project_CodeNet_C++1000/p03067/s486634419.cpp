#include<bits/stdc++.h>
//#include<atcoder/all>

using namespace std;
//using namespace atcoder;

int main(){
    int a,b,c;
    cin>>a>>b>>c;
    if((a<=c&&c<=b)||(b<=c&&c<=a)) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}
