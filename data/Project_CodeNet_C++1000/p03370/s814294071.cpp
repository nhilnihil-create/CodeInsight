#include<iostream>

using namespace std;

int N,X;
int m[1003];
int main(){
    cin>>N>>X;
    for(int i=0;i<N;++i)cin>>m[i];

    int sum,Min;
    sum=0;
    Min=10000000;
        for(int i=0;i<N;++i){
            sum+=m[i];
                if(Min>m[i])Min=m[i];
        }
    cout<<N+(X-sum)/Min;
}
