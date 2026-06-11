#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int A,B,C;
    cin >>A>>B>>C;
    int maxa=max(max(A,B),C);
    int maxb=maxa;
    int maxc=maxa;
    maxa-=A;
    maxb-=B;
    maxc-=C;
    int count =maxa/2+maxb/2+maxc/2;
     if(maxa-maxa/2*2==0&&maxb-maxb/2*2==0&&maxc-maxc/2*2==0){
        cout<<count<<endl;
        return 0;
    }
    else if(maxa-maxa/2*2==1&&maxb-maxb/2*2==1){
        count++;
    }
    else if(maxb-maxb/2*2==1&&maxc-maxc/2*2==1){
        count++;
    }
    else if(maxa-maxa/2*2==1&&maxc-maxc/2*2==1){
        count++;
    }
    else{
        count++;
        count++;
    }
    cout<<count<<endl;
}