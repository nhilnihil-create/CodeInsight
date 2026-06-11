#include <bits/stdc++.h>
#include <math.h>
using namespace std;
int main(){
    int N,D,X,A;
    cin>>N>>D>>X;
    int count=0;
    while(cin>>A){
    count+=(D-1)/A+1;
    }
    cout<<X+count<<endl;
    return 0;
}