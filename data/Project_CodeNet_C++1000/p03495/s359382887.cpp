#include<iostream>
#include<algorithm>

using namespace std;

int main(){
    int N,K;
    cin>>N>>K;
    int A[N];
    for(int i=0;i<N;++i)cin>>A[i];

    int count[200000]={0};
        
        for(int i=0;i<N;++i){
            count[A[i]-1]++;
        }
        
        // for(int i=0;i<N;++i){
        //     cout<<"count:"<<count[i]<<"\n"s;

        // }
           
        sort(count,count+N,greater<int>());
            
    int  sum=0;

                for(int i=0;i<K;++i){
                    sum+=count[i];
                }
    cout<<N-sum;
    

}