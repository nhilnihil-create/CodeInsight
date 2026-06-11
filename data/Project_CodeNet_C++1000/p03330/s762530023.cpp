#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
 

int main() {
    int N, C;
    cin>>N>>C;
    int D[C][C];
    vector<int>zeroarr, onearr, twoarr;
    for(int i=0;i<C;++i){
        for(int j=0;j<C;++j){
            cin>>D[i][j];
        }
    }
    int tmp;
    for(int i=0;i<N;++i){
        for(int j=0;j<N;++j){
            cin>>tmp;
            tmp--;
            if((i+j)%3==0) zeroarr.push_back(tmp);
            else if((i+j)%3==1) onearr.push_back(tmp);
            else twoarr.push_back(tmp);
        }
    }
    vector<int> zeroscore, onescore, twoscore;
    int zerotmp;
    for(int i=0;i<C;++i){
        zerotmp = 0;
        for(int j=0;j<zeroarr.size();++j){
            zerotmp += D[zeroarr[j]][i];
        }
        zeroscore.push_back(zerotmp);
    }
    int onetmp;
    for(int i=0;i<C;++i){
        onetmp = 0;
        for(int j=0;j<onearr.size();++j){
            onetmp += D[onearr[j]][i];
        }
        onescore.push_back(onetmp);
    }
    int twotmp;
    for(int i=0;i<C;++i){
        twotmp = 0;
        for(int j=0;j<twoarr.size();++j){
            twotmp += D[twoarr[j]][i];
        }
        twoscore.push_back(twotmp);
    }
 
    long ans = 1e9;
    for(int i=0;i<C;++i){
        for(int j=0;j<C;++j){
            for(int k=0;k<C;++k){
                if(i!=j & j!=k & k!=i & ans > zeroscore[i] + onescore[j] + twoscore[k]) ans = zeroscore[i] + onescore[j] + twoscore[k];
            }
        }
    }
    cout<<ans<<endl;
}
