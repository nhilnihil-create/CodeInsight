#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<long long> cir(vector<long long>x){
    vector<long long>Y;
    int count=0;
    Y.push_back(x[0]);
    for(int i=1;i<x.size();i++){
//        cout<<x[i]<<endl;
        if(x[i]%x[0]==0){
            count++;
        }else{
            Y.push_back(x[i]%x[0]);
        }
        if(x[i]%x[0]==1){
            cout<<1<<endl;
            exit(0);
        }

    }
//    cout<<count<<" "<<x.size()-1<<endl;
    if(count==x.size()-1){
        cout<<Y[0]<<endl;
        exit(0);
    }
    sort(Y.begin(),Y.end());
    cir(Y);
}

int main()
{
    int N;
    cin>>N;
    vector<long long>A(N);
    for(int i=0;i<N;i++){
        cin>>A[i];
    }
    sort(A.begin(),A.end());
    cir(A);
}