#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
typedef long long ll;

int main(){
    int a,b,c,d;
    cin >> a >> b >> c >> d;
    int l=a+b,r=c+d;
    string message;
    if(l<r){
        message="Right";
    }else if(l>r){
        message="Left";
    }else{
        message="Balanced";
    }
    cout << message << endl;
}