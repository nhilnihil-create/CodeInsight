#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    int X,Y,Z,K;cin>>X>>Y>>Z>>K;
    vector<long long>A(X),B(Y),C(Z);
    for(int i=0;i<X;i++)cin>>A[i];
    for(int i=0;i<Y;i++)cin>>B[i];
    for(int i=0;i<Z;i++)cin>>C[i];
    //cout<<" hi1"<<endl;

    vector<long long>AB;
    for(int i=0;i<X;i++) for(int j=0;j<Y;j++) AB.push_back(A[i]+B[j]);
    sort(AB.begin(),AB.end(),greater<long long>());
    AB.resize(K);
    //cout<<"hi2"<<endl;

    vector<long long>ABC;
    for(int i=0;i<AB.size();i++)for(int j=0;j<Z;j++)ABC.push_back(AB[i]+C[j]);
    sort(ABC.begin(),ABC.end(),greater<long long>());
    //cout<<"hi3"<<endl;
    for(int k=0;k<K;k++)cout<<ABC[k]<<endl;
}