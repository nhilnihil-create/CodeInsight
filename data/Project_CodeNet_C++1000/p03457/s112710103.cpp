#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,t,x,y;
    int tp,xp,yp;
    int a,b,c;
    bool ans=true;
    cin >> n;
    tp=0;
    xp=0;
    yp=0;
    for(int i=0;i<n;i++){
        cin >> t >> x >> y;
        a=abs(t-tp);
        b=abs(x-xp);
        c=abs(y-yp);
        if((a<b+c)||((a-b-c)%2!=0)){
            ans=false;
        }
        else{
            tp=t;
            xp=x;
            yp=y;
        }
    }
    if(ans){
        cout << "Yes" << endl;
    }
    else{
        cout << "No" << endl;
    }
}
