#include <iostream>
#include<cmath>
#include<vector>
using namespace std;
#define ll long long
#define ld long double

int main(void){
 ll n;
 cin>>n;
 
 vector<vector<ll>> vec(n-1, vector<ll>(3));
 
 for(int i=0;i<n-1;++i){
     for(int j=0;j<3;j++)
     cin>>vec[i][j];
 }

ll time1=0;
for(int i=0;i<n-1;i++){
    time1= vec[i][1]+vec[i][0];
    for(int j=i+1;j<n-1;++j){
        if(vec[j][1]>=time1){
            time1= vec[j][1];
        }
        else{
            
            ll t1= (time1- vec[j][1])%vec[j][2];
            if(t1!=0){
                time1+=vec[j][2]-t1;
            }
        }
        time1+=vec[j][0];
    }
    cout<<time1<<endl;;
}
cout<<0<<endl;
}