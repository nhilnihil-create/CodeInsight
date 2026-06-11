#include <bits/stdc++.h>
using namespace std;
 
int main(){
    int N,H,W;
    cin>>N>>H>>W;
    int count =0;
    for(int i=1;i<=N;i++){
        int A,B;
        cin>>A>>B;
        if(H<=A&&W<=B){
            count++;
        }
    }
    cout<<count<<endl;
 
}
