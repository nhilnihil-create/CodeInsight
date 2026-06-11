#include<iostream>
#include<vector>
using namespace std;

int main() {
    int N;
    cin>>N;
    bool prime[5000000];
    for(long i=0;i<5000000;++i){
        prime[i] = true;
    }
    prime[0] = false;
    prime[1] = false;
    for(long i=2;i<5000000;++i){
        if(prime[i]==false)continue;
        else {
            long j = 2;
            while(i*j<5000000){
                prime[i*j] = false;
                j++;
            }
        }
    }
    vector<int> ans;
    int now = 0;
    for(int i=0;i<N;++i){

        while(!((prime[now]==true) & (now%5==1))){
            now++;
        }
        ans.push_back(now);
        now++;
    }
    for(int i=0;i<N;++i){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}
