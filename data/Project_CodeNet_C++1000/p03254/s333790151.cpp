#include <bits/stdc++.h>
using namespace std;
 

    using Graph = vector<vector<int>>;
 
int main() {

    int64_t N,x;
    cin>>N>>x;


    vector<int64_t> a(N);
    for(int i=0;i<N;i++){
        cin>>a.at(i);
    }
    

    sort(a.begin(),a.end());


    //お菓子を配る。喜ばない子供がいてもよい。
    int64_t sum=0;
    int64_t distribution_number=0;
    for(int i=0;i<N;i++){
        sum+=a.at(i);

        if(sum>x){
            distribution_number=i;
            break;
        }
    }

    if(sum==x)
        cout<<N<<endl;
    else if(distribution_number==0 && sum<x)
        cout<<N-1<<endl;
    else
        cout<<distribution_number<<endl;

 	return 0;
}