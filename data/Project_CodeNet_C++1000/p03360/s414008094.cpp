#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
    int a,b,c,k;
    cin >> a >> b >> c >> k;
    for(int i=0;i<k;i++){
        if(a==max(a,max(b,c))) a=a*2;
        if(b==max(a,max(b,c))) b=b*2;
        if(c==max(a,max(b,c))) c=c*2;
    }
    cout << a+b+c << endl;
}
