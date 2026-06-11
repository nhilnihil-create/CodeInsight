#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


int main()
{
    int N,M;
    cin>>N>>M;
    vector<int>X(M),Y;
   
    for(int i=0;i<M;i++){
        cin>>X[i];
    }
     if(N>=M){
        cout<<0<<endl;
        exit(0);
    }
    sort(X.begin(),X.end());
    for(int i=1;i<M;i++){
        Y.push_back(abs(X[i]-X[i-1]));
    }
    sort(Y.begin(),Y.end());
    long long sum=0;
    for(int i=0;i<M-N;i++){
        sum+=Y[i];
    }
    cout<<sum<<endl;

}