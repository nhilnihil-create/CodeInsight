#include <iostream>
#include <vector>

int main(){
    using namespace std;
    int N,A,B;
    cin>>N>>A>>B;

    int mina=0;
    int mid=0;
    int maxb=0;
    int p;
    for(int i=0;i<N;i++){
        cin>>p;
        if(p<=A){
            mina++;
        }else if(p<=B){
            mid++;
        }else{
            maxb++;
        }
    }

    int ans=mina;
    if(ans>mid){
        ans=mid;
    }
    if(ans>maxb){
        ans=maxb;
    }
    cout<<ans<<endl;
    
    return 0;
}