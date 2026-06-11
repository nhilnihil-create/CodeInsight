#include <bits/stdc++.h>
#include <math.h>
using namespace std;
int main(){
    int N,D,X,A;
    cin>>N>>D>>X;
    int count=0;
    while(cin>>A){
    int i=0;
    while((i*A+1)<=D){count++;i++;}
    }
    cout<<X+count<<endl;
    return 0;
}