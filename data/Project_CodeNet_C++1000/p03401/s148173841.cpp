#include<bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;
    vector<int> a(N);
    for(int i=0;i<N;i++){
        cin >> a.at(i);
    }
    int m=abs(a.at(0))+abs(a.at(N-1));
    for(int i=1;i<N;i++){
        m+=abs(a.at(i)-a.at(i-1));
    }
    for(int i=0;i<N;i++){
        int o_r,n_r;
        if(i==0){
            o_r=abs(a.at(0))+abs(a.at(0)-a.at(1));
            n_r=abs(a.at(1));
        }
        else if(i==N-1){
            o_r=abs(a.at(N-1))+abs(a.at(N-1)-a.at(N-2));
            n_r=abs(a.at(N-2));
        }
        else{
            o_r=abs(a.at(i+1)-a.at(i))+abs(a.at(i)-a.at(i-1));
            n_r=abs(a.at(i+1)-a.at(i-1));
        }
        cout << m+n_r-o_r << endl;
    }
}