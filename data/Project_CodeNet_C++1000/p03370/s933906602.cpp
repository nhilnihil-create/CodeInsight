#include <iostream>

using namespace std;

int main(){
    int N,X;
    int m[110];
    cin>>N>>X;
    int res = X;
    int min = 1000;
    for(int i=0;i<N;i++){
        cin>>m[i];
    }for(int i=0;i<N;i++){
        res = res-m[i];
        if(min > m[i]){
            min = m[i];
        }
    }
    int n = res/min;
    cout<<N+n<<endl;
}