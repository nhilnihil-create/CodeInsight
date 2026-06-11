#include <bits/stdc++.h>
using namespace std;
 

    using Graph = vector<vector<int>>;
 
int main() {

    int N;
    cin>>N;


    vector<int>  a(N);
    for(int i=0;i<N;i++){
        cin>>a.at(i);
    }

    int sum=0;
    int length=1;
    for(int i=0;i<N-1;i++){
        if(a.at(i)==a.at(i+1)){
            length++;
        }
        else
        {
            sum+=length/2;
            length=1;
        }
        
        if(i==N-2){
            sum+=length/2;
            length=1;
        }
    }

    cout<<sum<<endl;

 	return 0;
}