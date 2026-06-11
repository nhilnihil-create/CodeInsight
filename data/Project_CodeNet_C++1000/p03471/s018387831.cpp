#include<bits/stdc++.h>
using namespace std;

int main(){
    int ans1=-1, ans2=-1, ans3=-1;
    int N, Y; cin>>N>>Y;
    for(int i=0; i<=N; i++){
        for(int j=0; j+i<=N; j++){
            if(10000*i + 5000*j + 1000*(N-i-j) == Y){
                ans1=i;
                ans2=j;
                ans3=N-i-j;
            }
        }
    }
    cout<<ans1<<" "<<ans2<<" "<<ans3<<endl;
}
