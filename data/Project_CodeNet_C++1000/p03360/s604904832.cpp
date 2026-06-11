#include<bits/stdc++.h>
using namespace std;
int main(){
    int a,b,c,k;
    cin >> a>>b>>c>>k;
    int h=0;
    if(h<a)h=a;
    if(h<b)h=b;
    if(h<c)h=c;
    //cout << h << endl;
    
    if(h==a){
        for(int i=0;i<k;i++){
            a=a*2;
        }
    }
    else if(h==b){
        for(int i=0;i<k;i++){
            b=b*2;
        }
    }
    else if(h==c){
        for(int i=0;i<k;i++){
            c=c*2;
        }
    }
    cout << a+b+c << endl;
    return 0;

    
}
