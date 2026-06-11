#include <bits/stdc++.h>
using namespace std;


int main(){
    int N,D,X;
    vector<int> A(100);
    cin>>N;
    cin>>D>>X;
    for(int i=0;i<N;i++){
        cin>>A.at(i);
    }
    int eat=0;
    for(int i=0;i<N;i++){
        eat+=(1+(int)((D-1)/A.at(i)));
    }
    cout<<X+eat<<endl;
    return 0;
}
