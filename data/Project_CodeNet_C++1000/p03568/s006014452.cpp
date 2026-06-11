#include <bits/stdc++.h>
#include <math.h>
using namespace std;
int main(){
    int N;
    cin>>N;
    vector<int>A(N);
    for(int i=0;i<N;i++){
        cin>>A.at(i);
    }
    int all=0;int k=1;
    all=pow(3,N);
    for(int i=0;i<N;i++){
        if(A.at(i)%2==0){k*=2;}
    }
    cout<<all-k<<endl;

    return 0;
}