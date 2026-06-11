#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int a[100005];
int main(){
    std::ios::sync_with_stdio(false);
    int a,b,c;
    cin>>a>>b>>c;
    cout<<min(b/a,c)<<endl;
}

