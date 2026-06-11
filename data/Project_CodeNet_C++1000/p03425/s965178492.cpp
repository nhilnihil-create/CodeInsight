#include <bits/stdc++.h>
using namespace std;

long long N,march[5];

int main(){
    cin>>N;
    string S[N];
    for(int i=0;i<N;i++){
        cin>>S[i];
        if(S[i].at(0)=='M'){
            march[0]++;
        }else if(S[i].at(0)=='A'){
            march[1]++;
        }else if(S[i].at(0)=='R'){
            march[2]++;
        }else if(S[i].at(0)=='C'){
            march[3]++;
        }else if(S[i].at(0)=='H'){
            march[4]++;
        }
    }
    
    long long ans=(march[0]*march[1]*march[2])+(march[0]*march[1]*march[3])+(march[0]*march[1]*march[4])+(march[0]*march[2]*march[3])+(march[0]*march[2]*march[4])+(march[0]*march[3]*march[4])+(march[1]*march[2]*march[3])+(march[1]*march[2]*march[4])+(march[1]*march[3]*march[4])+(march[2]*march[3]*march[4]);
    cout<<ans<<endl;
    return 0;
}